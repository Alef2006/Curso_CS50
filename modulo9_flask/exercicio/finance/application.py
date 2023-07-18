import os
import datetime
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    date=datetime.datetime.now()
    print(date)
    inventary=db.execute("SELECT *FROM inventary WHERE user_id =?",session["user_id"])
    users=db.execute("SELECT *FROM users WHERE id=?",session["user_id"])
    totalShares=db.execute("SELECT SUM(share_price) FROM inventary WHERE user_id=?",session["user_id"])


    if not inventary:
       return render_template("principal.html",cash=usd(users[0]["cash"]),date=date)
    if totalShares[0]["SUM(share_price)"]!=None:
       total=users[0]["cash"]+totalShares[0]["SUM(share_price)"]
       return render_template("principal.html",inventary=inventary,cash=usd(users[0]["cash"]),total=usd(total),date=date)

    return apology("Erro")

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method=="POST":
        users=db.execute("SELECT *FROM users WHERE id=?",session["user_id"])
        symbol=request.form.get("symbol")
        number=request.form.get("number")

        if not symbol:
           return apology("Escolha uma Empresa")
        if not number.isdigit():
           return apology("Digite apenas numeros!")
        if not number and symbol:
            return apology("Forneça o numero de acoes e a companhia")


        share=lookup(symbol)

        if share==None:
           return apology("Essa compania não existe")

        x=float(number)
        id_user=session["user_id"]
        finalPrice=round((share["price"]*x),2)

        if finalPrice>users[0]["cash"]:
           return apology("Desculpe mas você não tem dinheiro o suficiente para realizar a compra")

        finalCash=users[0]["cash"]-finalPrice
        inventary=db.execute("SELECT *FROM inventary WHERE user_id =? AND share_symbol=?",session["user_id"],symbol)

        if not inventary:
            db.execute("INSERT INTO inventary(user_id,share_name,share_symbol,number_shares,share_price) VALUES(?,?,?,?,?) ",session["user_id"],share["name"],share["symbol"],int(x),finalPrice)
            db.execute(f"UPDATE users SET cash='{finalCash}' WHERE id='{id_user}'")
            db.execute("INSERT INTO history(user_id,share_name,share_symbol,number_shares,share_price,action_type,action_data) VALUES(?,?,?,?,?,?,?)",session["user_id"],share["name"],share["symbol"],int(x),finalPrice,"buy",datetime.datetime.now())
            return redirect("/")
        else:
            value1=inventary[0]["number_shares"]+int(x)
            value2=round((inventary[0]["share_price"]+finalPrice),2)
            date=datetime.datetime.now()

            db.execute(f"UPDATE users SET cash='{finalCash}' WHERE id='{id_user}'")
            db.execute(f"UPDATE inventary SET number_shares='{value1}',share_price='{value2}' WHERE user_id='{id_user}' AND share_symbol='{symbol}'")
            db.execute("INSERT INTO history(user_id,share_name,share_symbol,number_shares,share_price,action_type,action_data) VALUES(?,?,?,?,?,?,?)",session["user_id"],share["name"],share["symbol"],int(x),finalPrice,"buy",datetime.datetime.now())

            return redirect("/")



    return render_template("buy.html",symbols=session["user_listActions"])

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    history=db.execute("SELECT *FROM history WHERE user_id=?",session["user_id"])

    return render_template("history.html",history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        session["user_listActions"]=[]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")

@app.route("/privacity", methods=["GET", "POST"])
@login_required
def privacity():

    if request.method=="POST":
        password=request.form.get("password")
        newPassword=request.form.get("newPassword")
        user=db.execute("SELECT *FROM users WHERE id=?",session["user_id"])


        if not password:
               return apology("Forneça sua senha para que possamos fazer a alteração!")
        if not newPassword:
               return apology("Forneça sua nova senha!")
        if not password and newPassword:
               return apology("Forneça os dados requisitados")

        newPasswordHash=generate_password_hash(newPassword)



        if not check_password_hash(user[0]["hash"],password) :
            return apology("Senha incorreta")
        else:
            id_user=session["user_id"]
            db.execute(f"UPDATE users SET hash='{newPasswordHash}' WHERE id='{id_user}'")
            return redirect("/")

    return render_template("alterar_dados.html")

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    symbol=request.form.get("symbol")


    if request.method=="POST":

       action=lookup(symbol)
       if action==None:
           return apology("Essa empresa não existe")
       else:
           session["user_listActions"].append(symbol)
           return render_template("quoted.html",action=action,price=usd(action["price"]))

    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    name=request.form.get("username")
    password=request.form.get("password")
    confirmPassword=request.form.get("confirmPassword")

    if request.method=="POST":

      if not name:
         return apology("Você deixou o campo nome em branco :(")
      elif not password:
         return apology("Você não forneceu uma senha :( ")
      elif not confirmPassword:
         return apology("Você não confirmou sua senha :( ")
      elif password!=confirmPassword:
          return apology("Você colocou uma senha que não bate com a senha de confirmação :( ")
      else:
          exists=db.execute("SELECT username FROM users WHERE username=?",name);
          if not exists:
             passwordHash=generate_password_hash(password)
             id=db.execute("INSERT INTO users(username,hash) VALUES(?,?)",name,passwordHash)
             return redirect("/")
          else:
              return apology("Esse nome de usuario ja existe :( ")

    return render_template("register.html",);



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    inventaryList=db.execute("SELECT *FROM inventary WHERE user_id =?",session["user_id"])
    if request.method=="POST":
        users=db.execute("SELECT *FROM users WHERE id=?",session["user_id"])
        symbol=request.form.get("symbol")
        number=request.form.get("number")

        if not symbol:
           return apology("Escolha uma Empresa")
        if not number.isdigit():
           return apology("Digite apenas numeros!")
        if not number and symbol:
            return apology("Forneça o numero de acoes e a companhia")


        share=lookup(symbol)

        if share==None:
           return apology("Essa compania não existe")

        x=float(number)
        id_user=session["user_id"]
        finalPrice=round((share["price"]*x),2)
        finalCash=users[0]["cash"]+finalPrice
        inventary=db.execute("SELECT *FROM inventary WHERE user_id =? AND share_symbol=?",session["user_id"],symbol)
        if not inventary:
            return apology("Você não possui ações nessa companhia")
        elif int(x)>inventary[0]["number_shares"]:
            return apology("você não possui esse numero de ações nessa companhia")
        else:
            value1=inventary[0]["number_shares"]-int(x)
            value2=round((inventary[0]["share_price"]-finalPrice),2)
            date=datetime.datetime.now()

            db.execute(f"UPDATE users SET cash='{finalCash}' WHERE id='{id_user}'")
            db.execute(f"UPDATE inventary SET number_shares='{value1}',share_price='{value2}' WHERE user_id='{id_user}' AND share_symbol='{symbol}'")
            db.execute("INSERT INTO history(user_id,share_name,share_symbol,number_shares,share_price,action_type,action_data) VALUES(?,?,?,?,?,?,?)",session["user_id"],share["name"],share["symbol"],int(x),finalPrice,"sell",datetime.datetime.now())

            return redirect("/")

    return render_template("sell.html",symbols=inventaryList)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
