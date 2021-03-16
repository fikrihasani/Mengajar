#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Queue{
    struct Node *front, *rear;
};

struct Queue *Q;

void createNode(int val, struct Node ** n){
    (*n) = (struct Node*)malloc(sizeof(struct Node)); 
    (*n)->data = val;
    (*n)->next = NULL;
}

void push(int val, struct Node ** n){
    struct Node *node = NULL;
    struct Node *iter = *n;
    createNode(val, &node);
    while (iter->next!=NULL)
    {
        /* code */
        iter = iter->next;
    }
    iter->next = node;
    Q->rear = iter;
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
    push(7,&n);
    printList(n);
    printf("\n");
}