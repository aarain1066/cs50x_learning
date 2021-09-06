// Modifies the volume of an audio file

// CS50 Lab4

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    uint8_t header[HEADER_SIZE];
    int16_t buffer;
    // TODO: Copy header from input file to output file

    // Going to have to read and write in the header, and then append the buffer

    /* Here, since we went ahead and defined the size of header, we can use that to our advantage in the
    `fread()` func in order to read the first 44 bytes of the header. So read a chunk of 44 bytes once from
    input (our stream) and store them into &header*/

    /* Here, you may be asking why we have the address on header defined explicitly but we just pass in the name
    of input later on. This is beacause funcs like `fread()` and `fwrite()` use file pointers, and input
    was already defined as a pointer up above. */

    fread(&header, sizeof(header), 1, input);

    // We do not modify the header, so pass it into our output file

    fwrite(&header, sizeof(header), 1, output);

    // This concludes copying the header over from the input to the output.


    // TODO: Read samples from input file and write updated data to output file



    // Close files
    fclose(input);
    fclose(output);
}
