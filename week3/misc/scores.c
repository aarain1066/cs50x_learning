#include <stdio.h>
#include <cs50.h>

//Prototype
float average(int length, int array[]);

int main(void){

    const int TOTAL = 3;

    // Want the values for all three scores, input by the user

    int scores[TOTAL];
    for (int i = 0; i < TOTAL; i++){

        scores[i] = get_int("Scores");
    }

    // Function average(below) is calculated, then used in printf

    printf("The average is %f\n", average(TOTAL, scores));

}

float average(int length, int array[])
{

    // calculate the average, which is the sum of all values, divided by number of values

    int sum = 0;

    for(int i = 0; i < length; i++)
    {
    sum = sum + array[i];
    }
    return sum/ (float) length;

}