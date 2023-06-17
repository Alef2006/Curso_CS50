#include "helpers.h"
#include <math.h>

#define RED_COLOR 1
#define GREEN_COLOR 2
#define BLUE_COLOR 3

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int average=calculateGrayscale(image[i][j].rgbtRed,image[i][j].rgbtGreen,image[i][j].rgbtBlue);

            image[i][j].rgbtRed=average;
            image[i][j].rgbtGreen=average;
            image[i][j].rgbtBlue=average;
        }
    }
    return;
}
int calculateGrayscale(int valueA,int valueB,int valueC){
    int result=round((valueA+valueB+valueC)/3.0);
    return result;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){

          int newRED=round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
          int newGREEN=round(.349 *image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
          int newBLUE=round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
          if(newRED>255){
              newRED=255;
          }
          if(newGREEN>255){
             newGREEN=255;
          }
          if(newBLUE>255){
             newBLUE=255;
          }
          image[i][j].rgbtRed=newRED;
          image[i][j].rgbtGreen=newGREEN;
          image[i][j].rgbtBlue=newBLUE;


        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            for(int t=0;t<width;t++){
               if(j<t){
                   int red=image[i][t].rgbtRed;
                   int green=image[i][t].rgbtGreen;
                   int blue=image[i][t].rgbtBlue;

                   image[i][t].rgbtRed=image[i][j].rgbtRed;
                   image[i][t].rgbtGreen=image[i][j].rgbtGreen;
                   image[i][t].rgbtBlue=image[i][j].rgbtBlue;

                   image[i][j].rgbtRed=red;
                   image[i][j].rgbtGreen=green;
                   image[i][j].rgbtBlue=blue;
               }
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

        for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){

            int sumRed=0;
            int sumGreen=0;
            int sumBlue=0;

            int count=0;

               for(int y=i-1;y<=(i+1);y++){
                   for(int x=j-1;x<=(j+1);x++){
                    if(y<0 || y>height || x<0 || x>width){
                        continue;
                    }
                   sumRed=sumRed+image[y][x].rgbtRed;
                   sumGreen=sumGreen+image[y][x].rgbtGreen;
                   sumBlue=sumBlue+image[y][x].rgbtBlue;

                   count++;
                   }
               }

            int red=round(sumRed/count);
            int green=round(sumGreen/count);
            int blue=round(sumBlue/count);

            image[i][j].rgbtRed=red;
            image[i][j].rgbtGreen=green;
            image[i][j].rgbtBlue=blue;
        }
    }

    return;
}
