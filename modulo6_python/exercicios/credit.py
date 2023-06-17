import math
import cs50


# 4003600000000014
# 1234567891234567
def main():



   input=cs50.get_int("Qual o numero do seu cartão? ")
  
   value=input
   count=0
   count1=0
   count2=0
   numeroDeDigito=0
   valor=value
   valor1=value
   valor2=value
   j=0
   endNumber=0


   while valor>1:
      numeroDeDigito=numeroDeDigito+1;
      b=valor%10;
      if numeroDeDigito==16:
        endNumber=math.floor(b)
      elif numeroDeDigito==13:
        endNumber=math.floor(b)
      valor=valor/10

   while valor1>0:
      b =valor1%100
      o=math.floor(b/10)
      d=o*2
      if b>9:
        f=math.floor(d/10)
        p=d%10
        g=f+p
        count1=math.floor(count1+g)
      else:
        count1=math.floor(count1+d)
      valor1=valor1/100

   count+=math.floor(count1)

   while valor2>0:
       b =valor2%100
       i=b%10
       count2+=i
       valor2=math.floor(valor2/100);

   count+=math.floor(count2)
   
   
   if count%10>0:
      print("INVALID\n")
   elif(numeroDeDigito==15):
      print("AMERICAN EXPRESS\n")
   elif(endNumber==4):
      print("VISA\n")
   elif numeroDeDigito==16:
      print("MASTERCARD")
   

main()