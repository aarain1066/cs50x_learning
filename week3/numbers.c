#include <cs50.h>
#include <stdio.h>


//Linear search example 


int main(void){
    
    // Using a trick here to not pre-define the size of the array, don't have to bother
    //explicitly defining the array
    int numbers [] = {4, 6, 8, 2, 7, 5, 0};
    
    for(int i = 0; i < 7; i++){
        
        // for loop that will iterate 8 times
        if (numbers[i] == 0){
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}