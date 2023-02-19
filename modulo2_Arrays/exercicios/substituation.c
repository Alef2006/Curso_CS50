#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>


int criptografar();
int main(int lenght,string chave[]){

const int TOTAL =26;
const int LENGHT_KEY=strlen(chave[1]);
int count=0;
int countRepetidas=0;

if(lenght<2){
    printf("Uso: ./ chave de substituição\n");
    return 1;
}else if(lenght>2){
     printf("Uso: ./ chave de substituição\n");
    return 1;
}else{
   for(int i=1;i<lenght;i++){
     for(int t=0;t<LENGHT_KEY;t++){
         count=count+1;
         if(isdigit(chave[i][t])){
             printf("A chave deve conter apenas caracteres.\n");
             return 1;
        }
           char d=chave[i][t];
           if(isupper(d)){
              for(int e=0;e<LENGHT_KEY;e++){
             char c=toupper(chave[i][e]);
             if(d==c){
               countRepetidas=countRepetidas+1;
             }
           }
           }else{
               for(int e=0;e<LENGHT_KEY;e++){
             char c=tolower(chave[i][e]);
             if(d==c){
               countRepetidas=countRepetidas+1;
             }
           }
           }
    }
 }
}
 if(count<26 ||count>26){
    printf("A chave deve conter apenas 26 caracteres.\n");
    return 1;
}else if(countRepetidas>26){
    printf("A chave nâo deve conter caracteres repetidos.\n");
    return 1;
}else{
   criptografar(chave[1]);
    return 0;
}
}

int criptografar(string key){


string plaintext=get_string("plaintext: ");
const int TOTAL=strlen(plaintext);
int textCript[TOTAL];

for(int i=0;i<TOTAL;i++){

int c1=(plaintext[i]+26)%'Z';
int c2=(plaintext[i]+26)%'z';


if(isalpha(plaintext[i])){
 if(isupper(plaintext[i])){
 textCript[i]=toupper(key[c1-1]);
 }else{
 textCript[i]=tolower(key[c2-1]);
 }
}else{
    textCript[i]=plaintext[i];
}
}
printf("ciphertext: ");
for(int i=0;i<TOTAL;i++){
    printf("%c",textCript[i]);
}
printf("\n");

return 0;
}
