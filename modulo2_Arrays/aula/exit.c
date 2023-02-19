#include <cs50.h>
#include <stdio.h>

int main(int argc,string argv[])
{
    if(argc != 2){
        printf("Missing comand-line argument \n");
        return 1;
    }
    printf("Hello %s \n",argv[1]);
    return 0;
}
//O comando echo $? faz com que seja possivel ver o retorno da funcao no terminal
