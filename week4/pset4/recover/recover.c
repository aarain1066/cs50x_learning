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



int main(int argc, char *argv[]){


    // First test case, where if the arg count is too low

    if(argc < 2){

        printf("*** Error *** Usage: ./recover <__file_to_be_recovered__>\n");
        return 1;
    }

    // Second test case, where if the arg count is too high

    if(argc > 2){
        printf("Too many arguments entered, please only enter the 1.) program, followed by the 2.) data to be recovered. \n");
        return 2;
    }

    // Passing the test cases, move on to opening the file to a pointer

    FILE *raw_data = fopen(argv[1], "r");
    if(raw_data == NULL){

        printf("Could not open %s. \n ", argv[1]);
        return 3;
    }


    /* I think I'll want to index through the array, and if they four target bits are hit, then go on to fwrite a JPEG*/

    // we have to have an iteration here, where fread will eventually depend on i

    int *read_data_buffer = malloc(sizeof(int) * 512);

        if(read_data_buffer == NULL){

            printf("malloc error\n");
            return 4;

        }

    fread(read_data_buffer, sizeof(int) * 512, 1, raw_data);

    for(int i = 0; i < (sizeof(int) * 512); i++){

        if(read_data_buffer[i] == 0xff && read_data_buffer[i + 1] == 0xd8 && read_data_buffer[i + 2] == 0xff && (read_data_buffer[i + 3] & 0xf0) == 0xe0){

            printf("working\n");
        }
    }

    fclose(raw_data);
    free(read_data_buffer);


}