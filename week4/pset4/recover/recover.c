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

    FILE* rawDataPointer = fopen(argv[1], "r");
    if(rawDataPointer == NULL){

        printf("Could not open %s. \n ", argv[1]);
        return 1;
    }
    // raw data is now fed at pointer rawDataPointer

    // All check50 error checks pass at this point

    /*
    Error checking

    open input file (memory card)

    repeat this until end of memory card

        read 512 bytes into some space, we can call this a buffer

        if it is the first jpg ---> this means i'll need a counter
            if it's the first jpg
            write the first jpg
        if it not the first jpg
            close the current buffer
            open a new buffer
        else
            if already found jpg
                keep writing to it

    end of memory card
    free/close everything

    */

    // Initialize What I need

    BYTE buffer[BUFFER_SIZE];

    // To keep track of images

    int image_counter = 0;

    file_pointer == NULL;

    // ###.jpg'\0' = 8
    char imageNameAndNumber[8]








// close raw_data

}