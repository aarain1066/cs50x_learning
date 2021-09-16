#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node{

    int number;
    struct node *next;
}
node;

int main(void){

    node *list = NULL;

    node *n = malloc(sizeof(node));
    if(n == NULL){
        return 1;
    }

    n -> number = 1;
    n -> next = NULL;

    list = n;


    // Consider we want to add the neumber 2 to this list
    n = malloc(sizeof(node));
    if(n == NULL) {
        free(list);
        return 1;
    }

    n -> number = 2;
    n -> next = NULL;
    // Start at top of list (little block), follow arrow to node 1,
    // update it's pointer to sotre address of new node n
    list -> next = n;

    // Adding three to the list

    n = malloc(sizeof(node));
    if(n == NULL){
        free(list->next);
        free(list);
        return 1;
    }

    n -> number = 3;
    n -> next = NULL;
    list -> next -> next = n;

    // The can use print to observe

    // give temporary pointer pointing to the list, go to temp, so long
    // as it's not null, go to next block

    for(node *tmp = list; tmp != NULL; tmp = tmp -> next){

        printf("%i\n", tmp -> number);
    }

    // free the linked list

    while (list != NULL){

        node *tmp = list -> next;
        free(list);
        list = tmp;
    }


}