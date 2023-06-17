import cs50

def main():
   height=0
   while True:
        n = cs50.get_int("Height: ")
        if n > 0 and n<9:
            height+=n
            break

   for i in range(height):
       for t in range(height-i):
           print(" ",end="")

       for j in range(i):
           print("#",end="")

       print("\n")


main()