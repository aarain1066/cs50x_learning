#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void){
    
    string names [] = {"Bill", "Charlie", "Fred", "Geroge", "Ginny", "Percy", "Ron"};
    
    // Note that these are in alphabetical order
    
    for(int i = 0; i < 7; i++){
        
        // Can't do if(names[i] == "Ron"), works in other langs but not C
        // strcomp compares two strings
        // If confused on why zer0, read documentation for strcmp
        if (strcmp(names[i], "Ron") == 0){
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
} 