#include <stdio.h>
#include <stdlib.h>

struct dll
{
    /* data */
    int data;
    struct dll *next;
    struct dll *prev;
};

void printList(struct dll *n) 
{ 
    while (n != NULL) { 
        printf(" %d ", n->data); 
        n = n->prev; 
    } 
} 

int main(){
    struct dll *head = NULL;
    struct dll *tail = NULL;

    head = (struct dll *) malloc(sizeof(struct dll));
    tail = (struct dll *) malloc(sizeof(struct dll));
    head->data = 10;
    head->next = NULL;
    head->prev = NULL;
    tail->data = 11;
    tail->next = NULL;
    tail->prev = head;
    head->next = tail;
    printList(head->next);
}