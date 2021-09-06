#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Create a structure and search for values stored within it.

// Create the struct

typedef struct{
    string name;
    string number;
}
person;



// Above, we have the structure created, go on to create a search

int main(void){

    person people[2];

    people[0].name = "Brian";
    people[0].number = "727-555-5555";

    people[1].name = "Joe";
    people[1].number = "813-555-5555";

    for(int i = 0; i < 2; i++){

        if(strcmp(people[0].name, "Brian") == 0){

            printf("Found %s\n", people[0].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}