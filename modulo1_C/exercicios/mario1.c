#include<stdio.h>
#include<cs50.h>

int times(void);


int main(void)
{
 int a=times();

 for(int t=1;t<=a;t++){
     for(int e=a-t;e>=1;e--){
         printf(" ");
     }
     for(int b=1;b<=t;b++){
         printf("#");
     }
      printf("\n");
 }

}


int times(void){
  int n;

  do
  {
       n=get_int("height:");
  }
  while(n<=0 || n>=9);
  /*
  if(n<1)
  {
      printf("false");
  }
  else if(n>8)
  {
       printf("false");
  }
  else
  {
     printf("passou");
  }
*/
 return n;

}