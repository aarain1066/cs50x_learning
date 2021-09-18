// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "dictionary.h"

// Global variable count for `size()`
unsigned int counter = 0;


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    // create a node for cursor

    /* originally, i'd like this in the do statement in our do-while loop
    but C doesn't like that, as it treats cursor as it won't exist if the
    indexed hash if in fact NULL. C can't tell I only want it if
    it isn't NULL, so throw it up here. */
    node *cursor = malloc(sizeof(node));

    // if the spot in the hash table isn't NULL

    if(table[hash(word)] != NULL){

        // assign a value to next in the cursor
        do{
            cursor -> next = table[hash(word)];
        }
        // if the word isn't a match
        while(strcasecmp(word, cursor -> word) != 0);

            /* I couldn't include the if NULL part in the while loop like (... && "word" -> next != NULL
            because what happens if the last word is in fact a match? Then a false negative would trigger. */

            // So... if it's pointer isn't NULL...
            if(cursor -> next != NULL){

                // point the cursor pointer ONTO the next pointer of the current cursor (lol read that slowly)
                cursor = cursor -> next;
            }
            else{

                // if the next point is NULL, this means you reach the end and haven't found the word.
                // free the pointer and return false.
                free(cursor);
                return false;
            }

        // If you found the word, the while loop triggers false, and shoots you down here
        // so free the memory and return true
        free(cursor);
        return true;
    }

    // and of course, if the actualy index in the hash table is indeed NULL
    free(cursor);
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{

    // For the canon of this course, it is recc. requested to find a hashing algo online.

    /* I did some searching, and noticed some nice ones with varying complexity, that
    produced very little collisions. However, at this time, it is not neccessary to find
    the most optimal solution as this is a didactic scenario. A future consideration
    would be to go back here and implement a more robust hashing algo. for now, the algo from
    the following source (similar to an example in CS50) will do. */

    // https://joseph28robinson.medium.com/cs50-pset-5-speller-f9c89d08237e
    // by Austin Tackaberry

    // Start w/ a default value
    // Choosing long just incase for a larger word
    long sum = 0;

    // Iterate through each character of word
    for (int i = 0; i < strlen(word); i++)
    {

        // `tolower()` for when we compare the words later in `check()`
        sum += tolower(word[i]);
    }

    // Mod the sum in order to get an int back.
    return sum % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // `fopen()` the dictionary
    FILE *read_dictionary = fopen(dictionary, "r");

    // Error check
    if(read_dictionary == NULL){

        printf("Error in opening dictionary\n");
        return false;
    }

    // Read every single word from the file
    // CS50x gives advices to use `fscanf()`

    // Create a buffer for our read words.
    // Must be large enough for any __real__ word, plus the '\0'
    char scanned_word[LENGTH + 1];

    while(fscanf(read_dictionary, "%s", scanned_word) != EOF){

        // A word is successfully scanned if while == TRUE, Therefore..

        // Allocate memory of node, so we have a home for this scanned word
        node *new_node = malloc(sizeof(node));
        // Check that the real-estate for this home is still available
        if(new_node == NULL){

            printf("Error in memory allocation of words from dictionary\n");
            return false;
        }

        // This is where we'll need string.h, to copy the words from scanned words into nodes
        // Copy the scanned word from the buffer, into the new_node's word field
        // Set the new_nodes pointer to NULL, since we don't know where in the hash-table it belongs yet
        // This satisfies all of the values, at the moment, for new_node's struct definition
        strcpy(new_node -> word, scanned_word);
        new_node -> next = NULL;

        // Retrieve the hashing index from the hash function
        unsigned int hash_table_index = hash(new_node -> word);

        /* This returns an unsigned int where it will determine where in our hash table does the house
        for our new home (the node) belongs. If a new_node is a home for a successfully scanned word,
        Then the hashing index is though of as the zip code the home belongs to.*/

        if(table[hash_table_index] == NULL){

            /* This will satisfy the filling in the node completely, since new_node is
            a struct of node and we defined its values above as scanned word for word
            and NULL for next */

            table[hash_table_index] = new_node;
            free(new_node);
            counter++;
        }
        else{

            // Switch where the pointers point to

            new_node -> next = table[hash_table_index];
            table[hash_table_index] = new_node;
            return true;
            free(new_node);
            counter++;
        }


        /* At this point, we'll need to has the words from the dictionary to determine where
        to assign the word intothe has table */

        // `hash()` func takes in a "string", and returns an unsigned int
        //table[hash(scanned_word)] -> word = scan;

    }

    fclose(read_dictionary);
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    /* This isn't explicitly what the question asked for. Ideally, I would like
    Something along the lines of if(!load(argv[1]) so we can functionally
    see that the dictionary loaded, but this would be a huge waste of resrouces
    to call the function again. I debated setting a trigger by defning a bool
    global value to be true if dictionary loaded, but doing it by seeing if
    counter > 0 saves more space and practically does the same thing.*/

    if(counter > 0){

        return counter;

    }else{

        return 0;

    }

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
