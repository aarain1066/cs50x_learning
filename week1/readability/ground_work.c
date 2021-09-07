// Readability Homework Assignment, to be turned in

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// *******************************************************************************************************************************************************

// readability problem set

// index = 0.0588 * L - 0.296 * S - 15.8

// Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

// Design and implement a program, readability, that computes the Coleman-Liau index of the text.

// Implement your program in a file called readability.c in a directory called readability.

// Your program must prompt the user for a string of text (using get_string).

// Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase letter
//from a to z or any uppercase letter from A to Z, any sequence of letters separated by spaces should count as a word, and that any occurrence
//of a period, exclamation point, or question mark indicates the end of a sentence.

// Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.

// If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output
//"Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".

// ********************************************************************************************************************************************************

// -------------------------------- Practice -----------------------------------------------------

// Begin by writing a simple script that will take some user's text, and repeat it verbatim in the command line

// int main(void){

//     // Get user text

//     string user_input = get_string("Text: ");

//     printf("%s\n", user_input);

// }

// Now that you’ve collected input from the user, let’s begin to analyze that input by first counting the number of
// letters that show up in the text. Modify readability.c so that, instead of printing out the literal text itself,
// it instead prints out a count of the number of letters in the text.

// int compute_letters(string user_input);


// int main(void){


//      // Get user text, in form of a vector

//     string user_input = get_string("Text: ");

//     printf("%i", compute_letters(user_input));
//     printf(" letter(s)\n");

//  }

// int compute_letters(string user_input){

//     int letter_counter = 0;

//     for(int i = 0; i <= strlen(user_input); i++){

//         if(isalpha(user_input[i])){

//             letter_counter = letter_counter + 1;
//         }

//         letter_counter = letter_counter + 0;
//     }

//     return letter_counter;

// }


// Prototyping

int compute_letters(string user_input);

int compute_words(string user_input);

int compute_sentences(string user_input);


int main(void){


     // Get user text, in form of a vector

    string user_input = get_string("Text: ");

    printf("%i", compute_letters(user_input));
    printf(" letter(s)\n");
    printf("%i", compute_words(user_input));
    printf(" word(s)\n");
    printf("%i", compute_sentences(user_input));
    printf(" sentence(s)\n");

 }

// Compute letters func

int compute_letters(string user_input){

    int letter_counter = 0;

    for(int i = 0; i <= strlen(user_input); i++){

        if(isalpha(user_input[i])){

            letter_counter = letter_counter + 1;
        }

        letter_counter = letter_counter + 0;
    }

    return letter_counter;

}

// Compute words func

int compute_words(string user_input){

    int word_counter = 0;

    for(int i = 0; i <= strlen(user_input); i++){

        // if user enters nothing, catch that it is zero words

        if(user_input[0] == '\0'){

            word_counter = word_counter + 0;
        }

        // a space can indicate the end of a word

        else if(user_input[i] == ' '){

            word_counter = word_counter + 1;
        }

        // if user accidently ends on a space (no period).

        else if(user_input[(strlen(user_input) - 1)] == ' '){

             word_counter = word_counter + 0;

        }

        // NULL at end of string indicates string is complete, this will capture last word.

        else if(user_input[i] == '\0'){

            word_counter = word_counter + 1;
        }

        //otherwise

        word_counter = word_counter + 0;
    }

    return word_counter;
}

int compute_sentences(string user_input){

    int sentence_counter = 0;

    for(int i = 0; i < strlen(user_input); i++){

        if(user_input[i] == '.' ||
            user_input[i] == '!' ||
             user_input [i] == '?'){

            sentence_counter = sentence_counter + 1;
        }
    }

    return sentence_counter;
}












