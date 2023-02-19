#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>




int main(int argc, string argcv[])
{
  /*
if(argc==2){
    printf("Hello,%s\n",argcv[1]);
}else{
    printf("Hello World");
}
*/
if(argc==2){
    for(int i=0,n=strlen(argcv[1]);i<n;i++){
      printf("%c\n",argcv[1][i]);
    }
}else{
    printf("Hello World");
}




}