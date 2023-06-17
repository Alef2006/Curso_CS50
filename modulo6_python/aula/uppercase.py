import cs50

def main():
    s=cs50.get_string("Before:")

    for i in s:
        print(i.upper(),end="")

    """
    print("After: ",end="")
    print(s.upper())
    """
    
main()