#include <stdio.h>
#include <stdlib.h>


/*
Implement a program called recover that recovers JPEGs from a forensic image.

* Implement your program in a file called recover.c in a directory called recover.

* Your program should accept exactly one command-line argument, the name of a forensic image from which to recover JPEGs.

* If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, and main should return 1.

* If the forensic image cannot be opened for reading, your program should inform the user as much, and main should return 1.

* The files you generate should each be named ###.jpg, where ### is a three-digit decimal number, starting with 000 for the first image and counting up.

* Your program, if it uses malloc, must not leak any memory.
*/


// make a check that the pointer is NULL, and


int main(int argc, char *argv[]){

    if(argc < 2){

        printf("*** Error *** Usage: ./recover <__file_to_be_recovered__>\n");
        return 1;
    }

    if(argc > 2){
        printf("Too many arguments entered, please only enter the 1.) program, followed by the 2.) data to be recovered. \n");
        return 2;
    }

    else{

        printf("works!\n");

    }


    // First, we need to open a file before we can begin some action on it

   // FILE *raw_data = fopen("card.raw", "r");

    // open a function where we begin to read the file


}