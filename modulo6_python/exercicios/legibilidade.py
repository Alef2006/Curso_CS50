import cs50
import math 

def main():
    
    fimDeFrase=[
        "!",
        "?",
        "."
    ]
    letras=0
    palavras=1
    frases=0

    input=cs50.get_string("Text: ")

    for i in input:
        if i == " ":
            palavras+=1
        elif i in fimDeFrase:
            frases+=1
        elif i != "\\" or i != ",":
            letras+=1
    """
    print(f"{letras} letras")
    print(f"{palavras} palavras")
    print(f"{frases} frases")
    """
    result(letras,palavras,frases)
    


def result(letras,palavras,frases):
    frist=letras/palavras
    second=frases/palavras
    L=frist*100
    S=second*100

    indice=0.0588 * L - 0.296* S -15.8
    resultIndice=math.floor(indice)


    if resultIndice>16:
        print("Grade 16+")
    elif resultIndice<1:
        print("Before grade 1");
    else:
        print(f"Grade: {resultIndice}" )

main()
