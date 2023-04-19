#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<cs50.h>
#include<stdlib.h>


void swap(int *a,int *b);

int main(void){

int x=1;
int y=2;

printf("Before:\n");
printf("x is %i y is %i\n",x,y);

swap(&x,&y);

printf("After:\n");
printf("x is %i y is %i",x,y);

}


void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}