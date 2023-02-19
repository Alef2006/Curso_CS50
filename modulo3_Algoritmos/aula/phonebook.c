#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct 
{
    string name;
    string phoneNumber;
}
person;


int main(void){

person people[2];

people[0].name="Alef";
people[0].phoneNumber="79 99830-6045";

people[1].name="Givaldo";
people[1].phoneNumber="79 99803-8490";
   
   for(int i=0;i<2;i++){
      if(strcmp(people[i].name,"Alef")==0){
         printf("Found:%s\n",people[i].phoneNumber);
         return 0;
      }
      
   }

   printf("Not Found");
   return 1;


}