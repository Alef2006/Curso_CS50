#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int funcao(int i);
int main(void)
{

  int u=get_int("Digite qualquer numero:\n");
  funcao(u);

  /*int A=3;
int B=2;
int C=1;

printf("Nao Ordenada\n");

printf("A: %d\n",A);
printf("B: %d\n",B);
printf("C: %d\n",C);

printf("#######################################\n");

printf("Ordenada\n");

if(A<B && A<C){
printf("A: %d\n",A);
}else if(B<A && B<C){
  printf("A: %d\n",B);
}else if(C<A && C<B){
  printf("A: %d\n",C);
}


if(B<A && B>C){
printf("B: %d\n",B);
}else if(A<B && A>C){
  printf("B: %d\n",A);
}else if(C<A && C>B){
  printf("B: %d\n",C);
}

if(A>B && A>C){
printf("C: %d\n",A);
}else if(B>A && B>C){
  printf("C: %d\n",B);
}else if(C>A && C>B){
  printf("C: %d\n",C);
}



*/
/*

  int array[] = {10, 8, 9, 5, 6, 7, 4, 2, 1, 3};

  printf("Nao ordenado\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", array[i]);
  }

  // Do menor para o maior

  for (int i = 0; i < 10; i++)
  {

    for (int t = 0; t < 10; t++)
    {
      if (array[i] <array[t])
      {
        int n = array[i];
        array[i] = array[t];
        array[t] = n;
      }
    }
  }
  printf("Ordenacao do menor para o maior \n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", array[i]);
  }

  for (int i = 0; i < 10; i++)
  {

    for (int t = 0; t < 10; t++)
    {
      if (array[i] > array[t])
      {
        int n = array[t];
        array[t] = array[i];
        array[i] = n;
      }
    }
  }

  printf("Ordenacao do maior para o menor \n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", array[i]);
  }
*/




}

int funcao(int i){
   int d=i/2;
   printf("%d\n",d);
}