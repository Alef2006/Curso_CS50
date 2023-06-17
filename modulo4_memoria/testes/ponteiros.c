
#include<cs50.h>
#include <stdio.h>



void insertIN(int *var);

int main(void){

    int var=20;
    insertIN(&var);
    printf("VAR = %i\n",var);

}
void insertIN(int *var){

    *var=42;
}