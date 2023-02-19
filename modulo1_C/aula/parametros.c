#include<stdio.h>
#include<cs50.h>


int oneNumber(void);
int main(void)
{

    printf("bem vindo ao repetidor de palavras\n");
    string resp=get_string("Quer ultilizar o software:");
    string nao="sim";

    int i;
    if( resp == nao){
        printf("\nAvalia agente na loja");
    }else{
    string palavra=get_string("qual palavra voce quer que se repita:");
      i=oneNumber();
        for(int t=0;t<i;t++){
        printf("%s\n",palavra);
    }
     printf("Essa palavra se repetiu:%i\n ",i);
    }

}
int oneNumber(void){

   int  n;
    do{
        n=get_int("Quantas vezes voce quer que essa palavra se repita:");
    }
    while(n<1);
    return n;

       }