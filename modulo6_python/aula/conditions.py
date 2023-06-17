import cs50


x=cs50.get_int("X: ")

y=cs50.get_int("Y: ")

if x>y:
    print("X e maior que Y")
elif x<y:
    print("Y maior que X")
else:
    print("X igual a Y")