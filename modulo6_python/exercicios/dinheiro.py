

import math
import cs50


def main():

   troco=pegarValor();
   contador=0;

   if troco>25:
       result1=troco/25
       contador+=math.floor(result1)
       troco=troco%25

   if troco>10:
        result2=troco/10
        contador+=math.floor(result2)
        troco=troco%10

   if troco>5:
         result3=troco/5
         contador+=math.floor(result3)
         troco=troco%5

   if troco>=1:
        result4=troco/1
        contador+=math.floor(result4)
        troco=troco%1

   print(round(contador))






def pegarValor():

    r=0

    while True:
        n=cs50.get_float("troca devida:");
        if n>0:
            r+=n
            break

    n=round(r*100);

    return n


main()