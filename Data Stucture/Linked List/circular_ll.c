#include <stdio.h>
#include <stdlib.h>

struct Node
{
    /* data */
    int data;
    struct Node *next;
};

void create(int val, struct Node **n){
    *n = (struct Node *) malloc(sizeof(struct Node));
    (*n)->data = val;
    (*n)->next = NULL;
}

void insert(int val, struct Node ** n ){
    struct Node *tmp;
    create(val, &tmp);
    tmp->next = *n;
    *n = tmp;
    (*n)->next = *n;
}

void traverse(struct Node *n){
    struct Node *p = n->next;
    while (p != n->next)
    {
        /* code */
        printf("%d ",p->data);
        p = p->next;
    }
}

int main(){
    return 0;
}
