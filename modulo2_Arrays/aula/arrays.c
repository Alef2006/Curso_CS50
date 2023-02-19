#include<stdio.h>
#include<cs50.h>


float avarege(int length,int array[]);
int main(void)
{
   const int total=3;
    int scores[total];
    for(int i=0;i<total;i++){
        scores[i]=get_int("Scores:");
    }

    printf("Average: %0.1f\n",avarege(total,scores));

}
 float avarege(int length,int array[]){

   int sum=0;
   for(int i=0;i<length;i++){
         sum=sum+array[i];

   }

  return sum/(float)length;
 }