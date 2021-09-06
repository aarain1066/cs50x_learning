#include <stdio.h>
#include <cs50.h>

int main(void){
    
    //Get name
    string name = get_string("What is your name?\n");
    
    //Print the name the user provided
    printf("Hello %s\n", name);
}