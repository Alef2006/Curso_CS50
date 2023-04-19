#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef uint8_t BYTE;
int main(int argc,char * arqv[]){

if(argc!=3){

    fprintf(stderr,"Usage: copy SOURCE DESTINATION\n");
    return 1;
    
}

 FILE *source=fopen(arqv[1],"r");

  if(source==NULL){
     printf("This file cannot open %s\n",arqv[1]);
     return 1;
  }

  FILE *destination=fopen(arqv[2],"w");

  if(destination==NULL){
     
     fclose(source);
     printf("Can't create  %s\n",arqv[2]);
     return 1;

  }

  BYTE buffer;
  while(fread(&buffer,sizeof(BYTE),1,source)){
     fwrite(&buffer,sizeof(BYTE),1,destination);
  }

  fclose(destination);
  fclose(source);

}