import sys

def main():
    if len(sys.argv)!=2:
        print("Falta argumentos na linha de comando")
        sys.exit(1)

    print(f"Ola {sys.argv[1]}")

main()