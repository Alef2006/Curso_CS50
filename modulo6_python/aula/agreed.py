import cs50

s=cs50.get_string("Voce concorda?")

if s.lower() in ["s","sim"]:
    print("Agreed")
elif s.lower() in ["n","nao"]:
    print("Not agreed")