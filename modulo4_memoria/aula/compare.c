
#include<string.h>
#include<stdio.h>
#include<cs50.h>

int main(void){


    char* i=get_string("i:");
    char* j=get_string("j:");

    if(strcmp(i,j)==0){
       printf("Same\n");
    }else{
        printf("Different\n");
    }
}