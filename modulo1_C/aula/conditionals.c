#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    int a=get_int("a:");
    int b=get_int("b:");
    
    if(a==b)
    {
       printf("A equals B");
    }
    else if(a>b)
    {
         printf("A bigger than B");
    }
    else{
        printf("B bigger than A");
    }
}