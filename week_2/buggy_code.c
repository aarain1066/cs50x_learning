#include <stdio.h>

int main(void){

    // Print 10 hashes
    for (int i = 0; i <= 10; i++){

        printf("i is now %i\n", i);

        printf("#\n");

    }
}

// Wanted only 10 hashes but was getting 11, so to see what was really going on, we included the extra print statement `printf("i is now %i\n", i);`