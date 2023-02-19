#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{

    float letrasNumero = 0;
    float palavrasNumero = 0;
    float frasesNumero = 0;

    string text = get_string("Text: ");
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if (isspace(text[i]))
        {
            palavrasNumero = palavrasNumero + 1;
        }
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            frasesNumero = frasesNumero + 1;
        }
        else if (text[i] == '\'')
        {
            printf(" \n");
        }
        else if (text[i] == ',')
        {
            printf(" \n");
        }
        else
        {
            letrasNumero = letrasNumero + 1;
        }
    }

    palavrasNumero = palavrasNumero + 1;

    printf("Letras: %0.2f\n", letrasNumero);
    printf("Frases: %0.2f\n", frasesNumero);
    printf("Palavras: %0.2f\n", palavrasNumero);

    float a = letrasNumero / palavrasNumero;
    float b = frasesNumero / palavrasNumero;
    float L = a * 100;
    float S = b * 100;

    float indice = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(indice);

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before grade 1\n");
    }
    else
    {
        printf("Grade: %d\n", grade);
    }
}