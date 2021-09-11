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

    // This may look daunting, but this is just a problem with 9 scenarios.

    // In the furture, consider using macros and/or functions to reduce repetitiveness of code.
    // Using macros/functions not in the cannon of the course, and don't want to trip testing.

    /* For now, I will set the relative values here, so I can copy-paste them where needed

    ! ! ! NOTE: This is NOT a reccommended practice. The ideal method is again, leveraging
    macros/functions. This is only done to speed up coding and help the reader in comprehension
    of code. My personal preference is not not copy and paste.

    Assume "i" is indexing through rows and "j" is indexing through cols.

    Origin: image[i][j]
    North Pixel: image[i - 1][j]
    North-East: image[i - 1][j + 1]
    East: image[i][j + 1]
    South-East: image[i + 1][j + 1]
    South: image[i + 1][j]
    South-West: image[i + 1][j - 1]
    West: image[i][j - 1]
    North-West: image[i - 1][j - 1]

    */

    /* For readability, I am going to explain the orientation of how I imagine the element as we
    index through. I want you to think that the element we are currently on (at any given iteration) is
    the "origin". Consider it as the sticker on a map that says "you are here". First, lets
    consider the case where you are not near a boundry (i.e. you are surrounded by pixels in every
    immediate direction). The pixel directly above you is the "North" pixel. The pixel below you is
    the "South" pixel, and so on. Then, diagonally, the pixel to above-and-to-the-right of you is
    the "North West || NW" pixel. And so on. This nomenclature will help you read the code as
    we consider where we are at in the 2-d Array. This is going to help us understand which cases
    where we are encountering an edge in the array (where a pixel/pixels are missing in any direction). */

    RGBTRIPLE blurred_pixel;
    int avg_blue;
    int avg_green;
    int avg_red;

    for(int i = 0; i < height; i++){

        for(int j = 0; j < height; j++){

            /* Here we start indexing through the array. Imagine we start at the very top-left pixel. Then
            we continue to index through the top row until we hit the end. Then we skip down to the next
            row and continue (left to right) all the way to the bottom right pixel. That is how C will read
            the image. When we do our code, however, we are going to start with the corners first, then the
            edges, then the more general case of just a regular element surrounded by elements in every direction.*/


            // Case: Where we are at top left of image (image[0][0]) (corner)
            // Pixels to consider: East (E) image[i][j + 1], South-East (SE) image[i + 1][j + 1], and South (S) image[i + 1][j] and origin [i][j]

            if(i == 0 && j == 0){

                avg_blue = round( (image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j].rgbtBlue) / 4 );
                avg_green = round( (image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j].rgbtGreen) / 4 );
                avg_red = round( (image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed) / 4 );

                image[i][j].rgbtBlue = avg_blue;
                image[i][j].rgbtGreen = avg_green;
                image[i][j].rgbtRed = avg_red;

            }

            // Case: where we hit the top-right pixel (corner)

            if(i == 0 && j == (width -1)){

                // Consider only the W, SW, S, and origin[i][j] pixels

                avg_blue = round( (image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j].rgbtBlue ) / 4 );
                avg_green = round( (image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j].rgbtGreen ) / 4 );
                avg_red = round( (image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed ) / 4 );

                image[i][j].rgbtBlue = avg_blue;
                image[i][j].rgbtGreen = avg_green;
                image[i][j].rgbtRed = avg_red;

            }

            // Case: where we hit the bottom left pixel

            if(i == (height - 1) && j == 0){

                // Consider only the N, NE, E, and origin[i][j] pixels

                avg_blue = round( ( image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j].rgbtBlue ) / 4 );
                avg_green = round( ( image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j].rgbtGreen ) / 4 );
                avg_red = round( (image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i][j].rgbtRed ) / 4 );

                image[i][j].rgbtBlue = avg_blue;
                image[i][j].rgbtGreen = avg_green;
                image[i][j].rgbtRed = avg_red;

            }

            // Case: where we hit the bottom right pixel

            if(i == (height - 1) && j == (width - 1)){

                // Consider only the N, NW, W, and origin[i][j] pixels

                avg_blue = round( ( image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue ) / 4 );
                avg_green = round( ( image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen ) / 4 );
                avg_red = round( (image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed ) / 4 );

                image[i][j].rgbtBlue = avg_blue;
                image[i][j].rgbtGreen = avg_green;
                image[i][j].rgbtRed = avg_red;


            }

            // Now, moving along the top row (after first pixel until til _right_before_ the last pixel). (edge, top)

            if(i == 0 && j != (width - 1)){

                // Consider only the E, SE, S, SW, W, and origin[i][j] pixels

                avg_blue = round( (image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue)  / 6 );
                avg_green = round( (image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen)  / 6 );
                avg_red = round( (image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed)  / 6 );

                image[i][j].rgbtBlue = avg_blue;
                image[i][j].rgbtGreen = avg_green;
                image[i][j].rgbtRed = avg_red;

            }

            // Case: where we are at any (RHS) edge of the array, that is not the top right corner (edge, right)

            if(i > 0 && j == (width - 1)){

                // Consider the N, NW, W, SW, S, and origin[i][j] pixels

                avg_blue = round( (image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j].rgbtBlue ) / 6 );
                avg_green = round( (image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j].rgbtGreen ) / 6 );
                avg_red = round( (image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed ) / 6 );

                image[i][j].rgbtBlue = avg_blue;
                image[i][j].rgbtRed = avg_red;
                image[i][j].rgbtGreen = avg_green;

            }


            // Case: where are at any left-hand-side (LHS) edge of the array that is not the top left corner (edge, left)

            if(i > 0 && j == 0){

                // Consider the N, NE, E, SE, S, and origin pixels

                avg_blue = round( (image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j].rgbtBlue ) / 6 );
                avg_green = round( (image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j].rgbtGreen ) / 6 );
                avg_red = round( (image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed ) / 6 );

                image[i][j].rgbtBlue = avg_blue;
                image[i][j].rgbtRed = avg_red;
                image[i][j].rgbtGreen = avg_green;

            }

            // Case: where we are at the bottom edge of the array, that again is not a corner. (edge, bottom)

            if(i == (height - 1) && j > 0){

                // Consider only the W, NW, N, NE, E, and origin[i][j] pixels

                avg_blue = round( (image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j].rgbtBlue)  / 6 );
                avg_green = round( (image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j].rgbtGreen)  / 6 );
                avg_red = round( (image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i][j].rgbtRed)  / 6 );

                image[i][j].rgbtBlue = avg_blue;
                image[i][j].rgbtGreen = avg_green;
                image[i][j].rgbtRed = avg_red;


            }

            // Case: Where our origin (Recall: Origin is our element currently indexed within the loop) is surrounded by elements





        }
    }

    return;
}
