import sys


def main():
   
   names=[
      "Beth",
      "Veronica",
      "Jughead",
      "Archie",
      "Reggie",
   ]

   if "Jughead" in names:
      print("FOUND! ;)")
      sys.exit(1)
   else:
      print("NOT FOUND! :(")
      sys.exit(0)

main()