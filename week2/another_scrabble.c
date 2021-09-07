#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <stdio.h>

// Points assigned to each character

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Array of capital letters' ASCII values.

int capital_letters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};

// Array of lower_case letters' ASCII values

int lower_letters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

// Keep running track of score

int score_counter[] = {};

//Prototype

int score_counter_func(string word);

int main (void){

    string word1 = get_string("Player 1's word:\n");
    string word2 = get_string("Player 2's word:\n");


        // create a function that will take a the word from P1 and P2, to eventually calculate a score from that

    int score1 = score_counter_func(word1);
    int score2 = score_counter_func(word2);

    if (score1 == score2){
        printf("It's a Tie!\n");
    }
    if (score1 > score2){
        printf("Player 1 wins!\n");
    }
    if(score2 > score1){
        printf("Player 2 wins!\n");
    }
}


// Create function that will take the score

int score_counter_func(string word){

    int score = 0;

    for(int i = 0; i < strlen(word); i++){

        if(isupper(word[i])){

            for(int c = 0; c < sizeof(capital_letters); c++){

                if(word[i] == capital_letters[c]){

                    score_counter[i] = POINTS[c];
                    score = score + score_counter[i];
                }
            }

        }
        else if(islower(word[i])){

            for(int c = 0; c < sizeof(lower_letters); c++){

                if(word[i] == lower_letters[c]){

                    score_counter[i] = POINTS[c];
                    score = score + score_counter[i];
                }
            }
        }
        else{
            i = i + 1;
        }
    }

    return score;


}