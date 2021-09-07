#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){

        for(int j = 0; j < width; j++){

            // Create the number that we wil use to make the gray scaler number

            // this is done by taking the RBG values (Note that in bmp's it's BGR) and averaging them

            int gray_avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // Set to the new average.

            image[i][j].rgbtBlue = gray_avg;
            image[i][j].rgbtGreen = gray_avg;
            image[i][j].rgbtRed = gray_avg;



        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
