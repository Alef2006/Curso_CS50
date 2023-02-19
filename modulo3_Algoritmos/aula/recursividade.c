#include <stdio.h>
#include <cs50.h>
#include <string.h>


int fatorial(int num);

int main(void){

int fatorialNumber=get_int("Fatorial de:");
int resultFatorialFunc=fatorial(fatorialNumber);
printf("O fatorial do numero %d e %d",fatorialNumber,resultFatorialFunc);


}
int fatorial(int num){
     
     if(num==0){
     return 1;
     }else{
        return num * fatorial(num-1);
     }



}