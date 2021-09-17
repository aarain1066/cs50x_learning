// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "dictionary.h"

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
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
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
        }
        else{

            // Switch where the pointers point to

            new_node -> next = table[hash_table_index];
            table[hash_table_index] = new_node;
            return true;
            free(new_node);
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
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
