#include <stdio.h>
#include <stdlib.h>

struct dll
{
    /* data */
    int data;
    struct dll *next;
    struct dll *prev;
} *head, *tail;

struct dll * createNode(int x){
    struct dll *node = (struct dll *)malloc(sizeof(struct dll));
    node->data = x;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void printList(struct dll *n) 
{ 
    while (n != NULL) { 
        printf(" %d ", n->data); 
        n = n->prev; 
    } 
} 

void insertEnd(int x){
    if (head == NULL)
    {
        printf("something here\n");
        /* code */
        tail = head = createNode(x);
    }else{
        struct dll *node = createNode(x);
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

void insertFront(int x){
    if (head == NULL)
    {
        printf("something here\n");
        /* code */
        // head->data = x;
        tail = head = createNode(x);
    }else{
        // create node
        struct dll *tmp = createNode(x);        
        tmp->next = head;
        head = tmp;
    }
    
}

void printHead(){
    struct dll *tmp = head;
    while(tmp != NULL){
        printf("%d\n",tmp->data);
        tmp = tmp->next;
    }
}

void printTail(){
    struct dll *curr = tail;
    while(curr != NULL){
        printf("%d\n",curr->data);
        curr = curr->prev;
    }
}

int main(){
    head = NULL;
    tail = NULL;

    insertEnd(10);
    insertEnd(20);
    insertEnd(1000);
    // printf("%d\n",head->data);
    printHead();
    printf("\n");
    printTail();

}