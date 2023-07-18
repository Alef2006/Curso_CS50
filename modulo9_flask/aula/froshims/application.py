import os
from flask import Flask,render_template,request,redirect
from cs50 import SQL
from flask_mail import Mail,Message


app=Flask(__name__)

#app.config[""]=os.getenv("")

app.config["MAIL_DEFAULT_SENDER"]=os.getenv("MAIL_DEFAULT_SENDER")
app.config["MAIL_PASSWORD"]=os.getenv("MAIL_PASSWORD")
app.config["MAIL_PORT"]=587
app.config["MAIL_SERVER"]="smtp.gmail.com"
app.config["MAIL_USE_TLS"]=True
app.config["MAIL_USERNAME"]=os.getenv("MAIL_USERNAME")

mail=Mail(app)

#db=SQL("sqlite:///froshims.db")

SPORTS=[
    "Futebol",
    "Queimado",
    "Volei",
     "Tenis"

    ]

REGISTRANTS={}

@app.route("/")
def index():
      return render_template("index.html",sports=SPORTS)


@app.route("/register",methods=["POST"])
def register():

    name=request.form.get("name")
    sport=request.form.get("sport")
    email=request.form.get("email")


    if not name:
        return render_template("error.html",message="Falta o seu nome :(")

    if not sport:
        return render_template("error.html",message="Você não escolheu um esporte :(")

    if sport not in SPORTS:
        return render_template("error.html",message="Esporte invalido")

    REGISTRANTS[name]=sport

     #db.execute("INSERT INTO registrants(name,sport,email) VALUES (?,?,?)",name,sport,email)

    message=Message("You are registered!",recipients=[email])
    mail.send(message)

    return  render_template("sucess.html",name=name)


