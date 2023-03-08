#include <stdio.h>
#include <cs50.h>
#include <string.h>


//int pesquisar(int i,int j);
int parImpar(int input);
int fatorial(int num);

typedef struct heroList
{
   string editora;
   string list[10];
};



int main(void)
{

  // int fatorialNumber = get_int("Fatorial de:\n");
   //int resultFatorialFunc = fatorial(fatorialNumber);
   //printf("O fatorial do numero %d e %d\n", fatorialNumber, resultFatorialFunc);
  // int input = get_int("Digite um numero natural:\n ");
 //  parImpar(input);

//pesquisar(0,0);


}
int fatorial(int num)
{

   if (num == 0)
   {
      return 1;
   }
   else
   {
      return num * fatorial(num - 1);
   }
}

int parImpar(int input)
{
   if (input == 1)
   {
   }
   else
   {
      if (input % 2 == 0)
      {
         return parImpar(input / 2);
      }
      else if (input % 2 > 0)
      {
         return parImpar(input + 1);
      }
   }
}
/*int pesquisar(int i,int j){
   if(i>3){
     return 0;
   }
   printf("Lista %d: %s\n",);
   
   pesquisar(i=1,j);
   
  

}*/

