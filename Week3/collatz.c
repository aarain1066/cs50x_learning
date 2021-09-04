#include <cs50.h>
#include <stdio.h>
#include <math.h>

// This file is an example of the collatz conjecture

// The collatz conjecture states, that you can always reach the number 1 by the following steps

// take a number "n"
    // if n == 1
        // stop
    // else if n is even
    // n = starting func(n/2)
    // else if n is odd
    // n = starting func (3n + 1)
    // else
        // error

// It is important to note that the question asks us to keep track of how many steps it takes to get to "1"

// Begin by importing header files

int collatzFunc(int n);

int stepCounter = 0;

int main(void){

    int n = get_int("Please enter your number n: ");
    
    if(n == 1){
        printf("%i", stepCounter);
        printf(" steps\n");
    }
    
    else{
    int steps =  collatzFunc(n);
    printf("%i", steps);
    printf(" steps\n");
    }

}

int collatzFunc(int n){

    stepCounter += 1;
    
    

    // Base Case

    // Case; n == even
    if(n % 2 == 0){


        return collatzFunc(n/2);
        return stepCounter;

    }

    else if(n % 2 != 0){

        return collatzFunc(3*n + 1);
        return stepCounter;

    }

   else return 1234567890;
}
