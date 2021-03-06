// Determine how long it takes for a population to reach a particular size

// Say we have a population (pop) of `n` llamas. Each year, `n/3` new llamas are born and `n/4` llamas pass away

// For example, if we were to start with `n = 1200` llamas, then in the first year, `1200 / 3 = 400` new llamas would be born and 1200 / 4 = 300 llamas would pass away. At the end of that year, we would have `1200 + 400 - 300 = 1300` llamas.

// Complete the implementation of population.c such that it calculates the number of years required for the population to grow from the start size to the end size.

// ----------------- Requirements -----------------

// Program is meant to ask the used for the starting population size
//  * if the user enters a number less than 9 (the minimum allowed population size), the user should be re-prompted to enter a starting population size until they enter a number that is greater than or equal to 9. (If we start with fewer than 9 llamas, the population of llamas will quickly become stagnant.)

// Your program should then prompt the user for an ending population size
//  *If the user enters a number less than the starting population size, the user should be re-prompted to enter an ending population size until they enter a number that is greater than or equal to the starting population size. 

// Your program should then calculate the (integer) number of years required for the population to reach at least the size of the end value.

// Finally, your program should print the number of years required for the llamas population to reach that end size, as by priting to the terminal `Years: n`, where `n` is the number of years. 

#include <cs50.h>
#include <stdio.h>


int main(void)
{
    // Prompt for start size
    
    int startingSize;
    do {
        startingSize = get_int("Please enter start population size, please note, must be greater than nine: ");
    }
    while(startingSize < 9);

    // Prompt for end size
    
    int endingSize;
    do {
        endingSize = get_int("Please enter an ending size, please note, must be greater than starting size: ");
    }
    while(endingSize < startingSize);
    

    // Calculate number of years until we reach threshold
    
    int n;
    int i;
    for(n = 0; startingSize < endingSize; n++){
        
        i = startingSize + (startingSize/3) - (startingSize/4);
        startingSize = i;
        
    }
    
     // Print number of years
    printf("Years: %i\n", n);

}


// Take-aways

//1.) at first I did...

    // int startingSize;
    // do{
    //    int startingSize = get_int....
//    }

// This was redundant, as we already initialize the `type` in the initial declaration (with int startingSize;)