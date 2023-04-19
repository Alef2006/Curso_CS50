
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<cs50.h>
#include<stdlib.h>

void draw(int h);

int main(void){

 int height=get_int("HEIGHT: ");
 draw(height);

}

void draw(int h){

    if(h==0){
      return;
    }
     
     draw(h-1);

     for(int i=0;i<h;i++){
       printf("#");
     }
     printf("\n");

}