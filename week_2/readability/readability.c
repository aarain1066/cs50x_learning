// Readability Assingment.

// Recall,  Coleman-Liau index formula:: index = 0.0588 * L - 0.296 * S - 15.8

// where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// prototypes
    int compute_words(string input);
    float compute_L(string input, int word_counter);
    float compute_S(string input, int word_count);
    int compute_CL(float compute_L, float compute_S);


int main(void){

    // Get user input

    string user_input = get_string("Text: ");

    // generate wordcount to be passed onto both funcions to calc `L` and `S`

    int word_count = compute_words(user_input);

    float L = compute_L(user_input, word_count);

    float S = compute_S(user_input, word_count);

    int C_L_index =  compute_CL(L, S);

    if(C_L_index < 1){

        printf("Before Grade 1\n");
    }

    else if (C_L_index >= 16){

        printf("Grade 16+\n");
    }

    else{

        printf("Grade %i\n", C_L_index);
    }
}

// word_counter func to be called within the funcs below it

int compute_words(string input){

    int word_counter = 0;

    for(int i = 0; i <= strlen(input); i++){

        // if user enters nothing, catch that it is zero words

        if(input[0] == '\0'){

            word_counter = word_counter + 0;
        }

        // a space can indicate the end of a word

        else if(input[i] == ' '){

            word_counter = word_counter + 1;
        }

        // if user accidently ends on a space (no period).

        else if(input[(strlen(input) - 1)] == ' '){

             word_counter = word_counter + 0;

        }

        // NULL at end of string indicates string is complete, this will capture last word.

        else if(input[i] == '\0'){

            word_counter = word_counter + 1;
        }

        //otherwise

        word_counter = word_counter + 0;
    }

    return word_counter;
}



// `compute_L` is the func that will calculate the avg letters per 100 words

float compute_L(string input, int word_count){


    int letter_counter = 0;

    for(int i = 0; i <= strlen(input); i++){

        if(isalpha(input[i])){

            letter_counter = letter_counter + 1;
        }

        letter_counter = letter_counter + 0;
    }

    return ( (float) letter_counter / word_count) * 100;

}

// `compute_S` is the func that will calculate the avg letters per 100 words

float compute_S(string input, int word_count){

    float sentence_counter = 0;

    for(int i = 0; i < strlen(input); i++){

        if(input[i] == '.' ||
            input[i] == '!' ||
             input [i] == '?'){

            sentence_counter = sentence_counter + 1;
        }
    }

    return (sentence_counter / word_count) * 100;
}

//Coleman-Liau index func

int compute_CL(float compute_L, float compute_S){

    float index = 0.0588 * compute_L - 0.296 * compute_S - 15.8;

    return round(index);
}
