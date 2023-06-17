#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <getopt.h>


#define BLOCK_SIZE 512


int main(int argc, char *argv[])
{

    if(argc!=2){
        printf("Sem argumento\n");
        return 1;
    }


char *file=argv[1];
FILE *input_file=fopen(file,"r");

if(input_file==NULL){
    printf("Could not open %s file\n",file);
    return 1;
}

uint8_t buffer[BLOCK_SIZE];
bool found_image=false;
char filename[8];
int count_image=0;
FILE *output_file=NULL;


 while (fread(buffer,BLOCK_SIZE,1, input_file)==1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

        if(found_image){
             fclose(output_file);
        }else{
            found_image=true;
        }

        sprintf(filename,"%03d.jpg",count_image);
        output_file=fopen(filename,"w");
        if(output_file==NULL){
            fclose(input_file);
            printf("Could not open %s\n",filename);
        }

        count_image++;
        }
        if(found_image){
            fwrite(buffer,BLOCK_SIZE,1,output_file);
        }


    }



 fclose(input_file);

 if(found_image){
     fclose(output_file);
 }



 return 0;

}
