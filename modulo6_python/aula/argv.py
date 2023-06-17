from sys import argv

def main(n):
    if len(n)==2:
        print(f"Hello,{n[1]}")
    else:
        print(f"Hello world")

main(argv)
"""

def main():
    if len(argv)==2:
        print(f"Hello,{argv[1]}")
    else:
        print(f"Hello world")

main()
"""