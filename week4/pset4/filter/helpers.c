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

// Below is a function for sepia, perfoming a quick check after converting an RBG val for sepia.

int rgbValCheck(int sepiaCalculatedVal)
{
    if (sepiaCalculatedVal > 255)
    {
        sepiaCalculatedVal = 255;
    }
    return sepiaCalculatedVal;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // indexing through height
    for(int i = 0; i < height; i++){

        // indexing through width
        for(int j = 0; j < width; j++){

            // starting at image[0][0], create the respective sepia values

            short sepiaRed = rgbValCheck(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            short sepiaGreen = rgbValCheck(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            short sepiaBlue = rgbValCheck(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));


            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    // Must go row by row, and re-sort the pixels.
    // Reverse each row

    // Since we are effectively doing a swap, we need a temp

    RGBTRIPLE temp_pixel;

    for(int i = 0; i < height; i++){

        for(int j = 0; j < width / 2; j++){

        // assign the temp before we start replacing the pixel

        temp_pixel = image[i][j];

        // take the pixel @ RHS index, and throw to LHS index

        image[i][j] = image[i][width - j - 1];

        // replace the value you just copied, with the temp

        image[i][width - j - 1] = temp_pixel;


        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
