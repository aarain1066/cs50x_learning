#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[]){

    // Let user type their name at the command prompt

    if (argc == 2){

        printf("Hello, %s\n", argv[1]);

    }
    else {
        printf("Hello, World\n");
    }
}