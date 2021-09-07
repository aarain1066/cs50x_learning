//scrap book
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// int main(void){
    
//     char c = 'A';
    
//     if(isupper(c)){
    
//     printf("%c\n", c);
//     }
// }

        // Aboove will print A

// int main(void){
    
//     char c = '!';
    
//     if(isupper(c)){
    
//     printf("%c\n", c);
//     }
// }

        // Above will print nothing
        
        // Therefore, we confirmed that using `isupper()` will only give us alpha values.
        
        // Move on to establishing both works, within a strin A!
        
        
string s = "Da@"; // declaration

        
int main (void){
    
    for(int i = 0, n = strlen(s); i < n; i++){
        
        
        string clean[500] = isupper(s[i]);
        
        printf("%s\n", clean);
        
    }
    
}
