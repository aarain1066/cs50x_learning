#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void){

    int *list = malloc(3 * sizeof(int));
    if(list == NULL){
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for(int i = 0; i < 3; i++){

        printf("%i\n", list[i]);
    }

    // Then at this point, we decide that we want a fourth element in our list.

    int *tmp = malloc(4 * sizeof(int));

    if(tmp == NULL){
        free(list);
        return 1;
    }

    // Copy the values from list

    for(int i = 0; i < 3; i++){

        tmp[i] = list[i];
    }

    tmp[3] = 4;

    list = tmp;

    for(int i = 0; i < 4; i++){

        printf("%i\n", list[i]);
    }

    free(list);

}