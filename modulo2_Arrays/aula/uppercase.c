
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


// Lembra do ASCII chart (codigo de caracters)
// toda tecla ou carcter possui um numero (codigo) representativo na tabela ASCII

int main(void){

    string s=get_string("Before: ");
    printf("After: ");


    for( int i=0,n=strlen(s); i<n ; i++){
        /*
        if(s[i]>='a' && s[i]<= 'z'){
            printf("%c",s[i]-32);
        }else{
            printf("%c",s[i]);
        }
        */
        //ou

        if(islower(s[i])){
            printf("%c",toupper(s[i]));
        }else{
            printf("%c",s[i]);
        }
    }
    printf("\n");


}