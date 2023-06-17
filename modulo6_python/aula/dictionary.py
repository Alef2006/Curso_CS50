import cs50

def main():

    phoneBook={
        "Alef":"+55 79 99830-6045",
        "Lucas":"+55 79 9909-6005",
        "Givaldo":"+55 79 99803-8490"
    }

    s=cs50.get_string("People:")

    print(f"O numero de {s} e {phoneBook[s]}")

main()