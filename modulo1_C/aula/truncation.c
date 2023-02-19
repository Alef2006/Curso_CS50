#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a = get_int("a:");
 
    int b= get_int("b:");
    
  float r= (float)a/(float)b;
   
    printf("%f\n", r);
} 