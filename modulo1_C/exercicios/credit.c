#include<cs50.h>
#include<stdio.h>
#include<math.h>


long cartaoDeCredito();
int main(void){


long alvo=cartaoDeCredito();

//4003600000000014
//1234567891234567


long count=0;
long count1=0;
long count2=0;
long numeroDeDigito=0;
long valor=alvo;
long valor1=alvo;
long valor2=alvo;
int j=0;
int endNumber=0;


//Numero de digitos.
while(valor>1){
numeroDeDigito=numeroDeDigito+1;
int b=valor%10;
if(numeroDeDigito==16){
    endNumber=b;
}else if(numeroDeDigito==13){
    endNumber=b;
}
valor=valor/10;

}

//Primeira Operacao.
while(valor1>0){
int b =valor1%100;
int o=b/10;
int d=o*2;
 if(b>9){
    int f=d/10;
    int p=d%10;
    int g=f+p;
    count1=count1+g;
    }else{
        count1=count1+d;
    }
valor1=valor1/100;
}
//Guardando primeiro resultado na variavel count(resultado final).
count=count+count1;

//Segunda operacao.
while(valor2>0){
int b =valor2%100;
int i=b%10;
count2=count2+i;
valor2=valor2/100;
}

//Guardando segundo resultado na variavel count(resultado final).
count=count+count2;


//Apartir desse ponto ja temos o resultado que sera testado,pois ele e a soma de ambos resultados das operacoes.



if(count%10>0){
    printf("INVALID\n");
}else if(numeroDeDigito==15){
        printf("AMERICAN EXPRESS\n");
}else if(endNumber==4){
   printf("VISA\n");
}else if(numeroDeDigito==16){
   printf("MASTERCARD\n");
}






}
long cartaoDeCredito(){


    long numero=get_long("Numero do cartão: ");
    return numero;
}