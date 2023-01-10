#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            float red=image[i][j].rgbtRed;
            float blue=image[i][j].rgbtBlue;
            float green=image[i][j].rgbtGreen;

            int average=round((red+blue+green)/3);
            image[i][j].rgbtRed=image[i][j].rgbtBlue=image[i][j].rgbtGreen=average;
        }}
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            RGBTRIPLE temp=image[i][j];
            image[i][j]=image[i][width-(j+1)];
            image[i][width-(j+1)]=temp;}}
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     // Create temp array
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
     // Loop through rows
    for (int i = 0; i < height; i++)
    {
        // Loop through columns
        for (int j = 0; j < width; j++)
        {
            // Initialise values
            float sum_red;
            float sum_blue;
            float sum_green;
            int counter;
            sum_red = sum_blue = sum_green = counter = 0;
            // For each pixel, loop vertical and horizontal
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check if pixel is outside rows
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // Check if pixel is outside columns
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Otherwise add to sums
                    sum_red += temp[i + k][j + l].rgbtRed;
                    sum_blue += temp[i + k][j + l].rgbtBlue;
                    sum_green += temp[i + k][j + l].rgbtGreen;
                    counter++;
                }
            }
            // Get average and blur image
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
   RGBTRIPLE old_image[height][width];
   for(int i=0; i<height; i++)
   {
    for(int j=0; j<height; j++)
    {
        old_image[i][j]=image[i][j];
    }
   }
   int  gx[3][3]={
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
     };
   int   gy[3][3]={
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
      };
 for(int i=0;i<height;i++)
 {
    for(int j=0;j<height;j++)
    {
       int mi[3]={i-1, i, i+1};
       int mj[3]={j-1, j, j+1};
     int gxr,gxg,gxb;
     gxr=gxg=gxb=0;

     int gyr,gyb,gyg;
      gyr=gyb=gyg=0;
        for(int isay=0; isay<3; isay++)
        {
          for(int jsay=0; jsay<3; jsay++)
          {
            int ni=mi[isay];
            int nj=mj[jsay];
            RGBTRIPLE pixel= old_image[ni][nj];

            gxr+=pixel.rgbtRed*gx[isay][jsay];
            gxb+=pixel.rgbtBlue*gx[isay][jsay];
            gxg+=pixel.rgbtGreen*gx[isay][jsay];

            gyr+=pixel.rgbtRed*gy[isay][jsay];
            gyb+=pixel.rgbtBlue*gy[isay][jsay];
            gyg+=pixel.rgbtGreen*gy[isay][jsay];
          }
        }
    int newr=round(sqrt(gxr*gxr+gyr*gyr));
    int newg=round(sqrt(gxg*gxg+gyg*gyg));
    int newb=round(sqrt(gxb*gxb+gyb*gyb));

    image[i][j].rgbtRed= newr<255? 255: newr;
    image[i][j].rgbtBlue= newb<255? 255: newb;
    image[i][j].rgbtGreen= newg<255? 255: newg;

    }
 }

    return;
}
