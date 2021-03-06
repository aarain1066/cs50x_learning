#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/*
Implement a program called recover that recovers JPEGs from a forensic image.

* Implement your program in a file called recover.c in a directory called recover.

* Your program should accept exactly one command-line argument, the name of a forensic image from which to recover JPEGs.

* If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, and main should return 1.

* If the forensic image cannot be opened for reading, your program should inform the user as much, and main should return 1.

* The files you generate should each be named ###.jpg, where ### is a three-digit decimal number, starting with 000 for the first image and counting up.

* Your program, if it uses malloc, must not leak any memory.
*/

const int BUFFER_SIZE = 512;
typedef uint8_t BYTE;


int main(int argc, char *argv[]){

    // First test case, where if the arg count is too low

    if(argc < 2){

        printf("*** Error *** Usage: ./recover <__file_to_be_recovered__>\n");
        return 1;
    }

    // Second test case, where if the arg count is too high

    if(argc > 2){
        printf("Too many arguments entered, please only enter the 1.) program, followed by the 2.) data to be recovered. \n");
        return 1;
    }

    // Passing the test cases, move on to opening the file to a pointer


    // `fopen()` takes in a pointer as it's first arg.

    // Recall that argv[1] is the file name of the deleted data we are trying to recover, I think readability is better this way.

    // Recall as well, the `fopen()` returns a pointer, therefore we derefence rawDataPointer to give it the val of an address
    FILE *rawDataPointer = fopen(argv[1], "r");
    if(rawDataPointer == NULL){

        printf("Could not open %s. \n ", argv[1]);
        return 1;
    }
    // raw data is now fed at pointer rawDataPointer

    // All check50 error checks pass at this point

    // Initialize What I need

    BYTE buffer[BUFFER_SIZE];

    // To keep track of images

    int imageCounter = 0;

    FILE *newFilePointer = NULL;

    // ###.jpg'\0' = 8
    char imageNumberForName[8];

    //repeat this until end of memory card

        //read 512 bytes into some space, we can call this a buffer

    while(fread(&buffer, BUFFER_SIZE, 1, rawDataPointer) == 1){

    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){

        // If it is not the first jpg, that means we are at a point in the loop where we are already writing a picture

        // Therefore, close the "current" picture

        if(!(imageCounter == 0)){
            fclose(newFilePointer);
        }

        // Otherwise, let's create the file and name for it

        // Create the name for the eventual file

        sprintf(imageNumberForName, "%03i.jpg", imageCounter);

        // Open the file and give it the name created from `sprintf()`

        newFilePointer = fopen(imageNumberForName, "w");

        // Tick the image counter to keep a running track of the images generated.

        imageCounter++;

    }
        // If we pass by the jpg header again, but if it's not the first file

        if(!(imageCounter == 0)){

            // If it's not the first image, keep writing to the file.

        fwrite(&buffer, BUFFER_SIZE, 1, newFilePointer);


        }

    }

fclose(rawDataPointer);
fclose(newFilePointer);
return 0;


}