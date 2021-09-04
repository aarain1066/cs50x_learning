// #include <cs50.h>
// #include <string.h>
// #include <stdio.h>

// int main(void){

//     string s = get_string("Before: ");

//     printf("After: ");

//     for(int i = 0, n = strlen(s); i < n; i++){

//         if(s[i] >= 'a'  &&  s[i] <= 'z'){

//             printf("%c", s[i] - 32);
//         }
//         else{
//             printf("%s\n", s);
//         }
//     }
//     printf("\n");
// }

//orrr

#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main(void){

    string s = get_string("Before: ");

    printf("After: ");

    for(int i = 0, n = strlen(s); i < n; i++){

        printf("%c", toupper(s[i]));
        }
    printf("\n");
}