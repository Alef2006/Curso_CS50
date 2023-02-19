#include<stdio.h>
#include<cs50.h>

int main (void);

void meow (void)
{
  printf("meow\n");
}


int main (void)
{
     for(int t=0;t < 50; t++){
        meow();
    }
}
