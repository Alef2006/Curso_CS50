#include "helpers.h"
#include  <math.h>
#include <stdint.h>
#include <stdio.h>

# define RGBT_RED 0
# define RGBT_GREEN 1
# define RGBT_BLUE 2











// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    const float n=3.0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
             float total=image[i][j].rgbtRed+image[i][j].rgbtRed+image[i][j].rgbtRed;
             int average=round(total/n);

             image[i][j].rgbtBlue=average;
             image[i][j].rgbtGreen=average;
             image[i][j].rgbtRed=average;
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
             if(j>t){
                 int red=image[i][j].rgbtRed;
                 int green=image[i][j].rgbtGreen;
                 int blue=image[i][j].rgbtBlue;

                 image[i][j].rgbtBlue=image[i][t].rgbtBlue;
                 image[i][j].rgbtRed=image[i][t].rgbtRed;
                 image[i][j].rgbtGreen=image[i][t].rgbtGreen;

                 image[i][t].rgbtBlue= blue;
                 image[i][t].rgbtRed=red;
                 image[i][t].rgbtGreen=green;


             }
        }
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
           int red=averageBlur(i,j,height,width,copy,RGBT_RED);
           int green=averageBlur(i,j,height,width,copy,RGBT_GREEN);
           int blue=averageBlur(i,j,height,width,copy,RGBT_BLUE);


           image[i][j].rgbtRed=red;
           image[i][j].rgbtGreen=green;
           image[i][j].rgbtBlue=blue;
        }
    }
    return;

}

int averageBlur(int i,int j,int height, int width, RGBTRIPLE image[height][width],int color_position){

    float count =0;
    int sum=0;
    for(int e = i-1; e <=(i+1); e++){
        for(int o = j-1; o <= (j+1); o++){
            printf("rodadad %f\n",count);
            printf("%i\n",e);
            printf("%i\n",e);
            if(e<0||e>=height || o<0||o>=width ){
                continue;
            }
            if(color_position==RGBT_RED){
                sum+=image[e][o].rgbtRed;

            }else if(color_position==RGBT_GREEN){
                sum+=image[e][o].rgbtGreen;
            }
            else{
               sum+=image[e][o].rgbtBlue;
            }
            count++;
        }
    }

    int average=round(sum/count);
    return average;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];

     for(int linha=0;linha<height;linha++){
         for(int coluna=0;coluna<width;coluna++){

             copy[linha][coluna].rgbtRed=image[linha][coluna].rgbtRed;
             copy[linha][coluna].rgbtGreen=image[linha][coluna].rgbtGreen;
             copy[linha][coluna].rgbtBlue=image[linha][coluna].rgbtBlue;
         }
     }
      int GX[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
      int GY[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};


     for(int i=0;i<height;i++){
         for(int j=0;j<width;j++){

              int redX=0;
              int greenX=0;
              int blueX=0;
              int redY=0;
              int greenY=0;
              int blueY=0;

              for(int x=0;x<3;x++){
                  for(int y=0;y<3;y++){

                      if(i-1+x<0 || i - 1 + x >height -1 || j - 1 +y < 0 || j - 1 +y > width -1){
                          continue;
                      }

                      redX= redX + (image[i-1 + x][j-1+y].rgbtRed *GX[x][y]);
                      greenX= greenX + (image[i-1 + x][j-1+y].rgbtRed*GX[x][y]);
                      blueX= blueX + (image[i-1 + x][j-1+y].rgbtRed*GX[x][y]);

                      redX= redX + (image[i-1 + x][j-1+y].rgbtRed *GY[x][y]);
                      greenX= greenX + (image[i-1 + x][j-1+y].rgbtRed*GY[x][y]);
                      blueX= blueX + (image[i-1 + x][j-1+y].rgbtRed *GY[x][y]);


                     int red=round(sqrt((redX*redX)+(redY*redY)));
                     int green=round(sqrt((greenX*greenX)+(greenY*greenY)));
                     int blue=round(sqrt((blueX*blueX)+(blueY*blueY)));

                     if(red>255){
                         red=255;
                     }
                     if(green>255){
                         green=255;
                     }
                     if(blue>255){
                         blue=255;
                     }

                     copy[i][j].rgbtRed=red;
                     copy[i][j].rgbtBlue=blue;
                     copy[i][j].rgbtGreen=green;
                  }
              }
         }
     }

     for(int i=0;i<height;i++){
         for(int j=0;j<width;j++){
             image[i][j].rgbtRed=copy[i][j].rgbtRed;
             image[i][j].rgbtBlue=copy[i][j].rgbtBlue;
             image[i][j].rgbtGreen=copy[i][j].rgbtGreen;
         }
     }

    return;
}









