#include <cs50.h>
#include <stdio.h>

// int main(void){

//     int i = get_int("i: ");
//     int j = get_int("j: ");

//     if ( i == j){

//         printf("Same\n");

//     }
//     else{
//         printf("Diffferent\n");
//     }
//     return 0;
// }

 //  let's do the same thing for strings, but at a low level

 int main(void){

     char *s = get_string("s: ");
     char *t = get_string(" t: ");

     if ( s == t){

         printf("Same\n)");
     }
     else printf("Different\n");
 }

 // Notiec, that if we enter the same string, like "HI" for both, we get
 // a result of "different" even through they are the same string.

 //  this is because we are not comparing the characters here, we are
 // comparing the addresses.
 
 
 // So correctly 
 
 