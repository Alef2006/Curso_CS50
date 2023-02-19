#include<stdio.h>
#include<cs50.h>
#include<string.h>


int main(void)
{


    //Podemos usar essa expressao s[i] != '\0' para descobri o tamanho do array durante o loop
    //ou usar a funcao strlen(nome da variavel)
    //opcao mais apropriada=int n=strlen(s); declarar o tamanho de uma vez

    string s=get_string("Input: ");
    printf("Output: ");
    int n =strlen(s);
    for(int i=0; i<n;i++){
        printf("%c",s[i]);
    }
    printf("\n");



}