#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void createNode(int val, struct Node ** n){
    (*n) = (struct Node*)malloc(sizeof(struct Node)); 
    (*n)->data = val;
    (*n)->next = NULL;
}

void push(int val, struct Node ** n){
    struct Node *node = NULL;
    createNode(val, &node);
    node->next = *n;
    *n = node;
}

void pop(struct Node **n){
    while((*n)->next->next != NULL){
        (*n) = (*n)->next;
    }
    struct Node *tmp = (*n)->next;
    (*n)->next = NULL;
    free(tmp);
}

void printList(struct Node *n){
    while(n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
}

int main(){
    struct Node *n = NULL;
    createNode(10, &n);
    printList(n);
    printf("\n");
    push(5,&n);
    printList(n);
    printf("\n");
    pop(&n);
    printList(n);
    printf("\n");
}