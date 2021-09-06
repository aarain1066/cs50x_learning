#include <stdio.h>
#include <cs50.h>
// int main(void){

//     int n = 50;
//     printf("%i\n", n);
// }

// See the address of n, with the operators & and *

// & - Address of operator, tells you want addres your variable is stored in

// * tells your program to look into (go into) the following address.


// int main(void){

//     int n = 50;
//     printf("%p\n", &n)
// }

// // print out address of where variable n is stored


// int main(void){

//     int n = 50;
//     printf("%i\n", *&n)
// }

// // star says go to this address, change back to %i

// -----------------------------------

// int main(void){

//     int n = 50;
//     int*p = &n; // this is the pointer, the syntax to point a varible to an integer
//     print("%p\n", p);
// }

// in memory, strings just store the address of the first character within
// the string. to demonstrate


// int main(void){

//     string s = "HI!";
//     printf("%p\n", s);
// }

// output is the addressof the first character of out string s 0x402004

// Now, let's go ahead and go into that address and get first address character and so on

int main(void){

    string s = "HI";
    printf("%p\n", &s); // address of pointer
    printf("%p\n", s); // address of first character
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
}

