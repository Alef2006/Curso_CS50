#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int tamanho, string chave[])
{
    int K;

    if (tamanho < 2)
    {
        printf("Você não digitou uma chave. Por favor forneça uma chave!\n");
        return 1;
    }
    else if (tamanho > 2)
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }
    else
    {
        for (int i = 1; i < tamanho; i++)
        {
            int n = strlen(chave[i]);
            for (int t = 0; t < n; t++)
            {
                if (isalpha(chave[i][t]))
                {
                    printf("Usage: ./ceasar key\n");
                }
                else
                {
                    K = atoi(chave[i]);
                }
            }
        }
    }

    string plaintext;

    if (K < 1)
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }
    else
    {

        plaintext = get_string("plaintext: ");

        const int e = strlen(plaintext);
        const int TOTAL = 26;

        int textoCript[e];
        int alfabetoU[TOTAL];
        int alfabetoL[TOTAL];

        for (int i = 0; i < TOTAL; i++)
        {
            char a = alfabetoU[i] = 65 + i;
            char b = alfabetoL[i] = 97 + i;
        }

        for (int i = 0; i < e; i++)
        {

            int t = plaintext[i] + K;
            int c1 = (plaintext[i] + K) % alfabetoL[25];
            int c2 = (plaintext[i] + K) % alfabetoU[25];

            if (isalpha(plaintext[i]))
            {
                if (islower(plaintext[i]))
                {
                    if (t > alfabetoL[25])
                    {
                        textoCript[i] = alfabetoL[c1 - 1];
                    }
                    else
                    {
                        textoCript[i] = t;
                    }
                }
                else if (isupper(plaintext[i]))
                {
                    if (t > alfabetoU[25])
                    {
                        textoCript[i] = alfabetoU[c2 - 1];
                    }
                    else
                    {
                        textoCript[i] = t;
                    }
                }
            }
            else
            {
                textoCript[i] = plaintext[i];
            }
        }

        printf("ciphertext: ");
        for (int i = 0; i < e; i++)
        {
            printf("%c", textoCript[i]);
        }
        printf("\n");
    }
}
