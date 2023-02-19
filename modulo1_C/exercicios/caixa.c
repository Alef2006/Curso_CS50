#include<stdio.h>
#include<cs50.h>
#include<math.h>



float pegarValor();
int main(void){

int troco=pegarValor();
int contador=0;






if(troco>=25){
    int result1=troco/25;
    contador=contador+result1;
 troco=troco%25;
}

if(troco>=10){
    int result2=troco/10;
    contador=contador+result2;
troco=troco%10;

}

if(troco>=5){
    int result3=troco/5;
    contador=contador+result3;
troco=troco%5;
}

if(troco>=1){
   int  result4=troco/1;
    contador=contador+result4;
troco=troco%1;
}



    printf("%d\n",contador);




}

float pegarValor(){

    float r;
    do{
      r=get_float("troca devida:");
    }
    while(r<0);

   int n=round(r*100);

    return n;
}