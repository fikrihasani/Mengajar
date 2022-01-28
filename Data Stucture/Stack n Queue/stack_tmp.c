#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *stack;

struct Node * createNode(int val){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node)); 
    n->data = val;
    n->next = NULL;
    return n;
}

void push(int val){
    struct Node *node = createNode(val);
    if(!stack){
        stack = node;
    }else{
        node->next = stack;
        stack = node;
    }

}

void pop(){
    if(stack == NULL){
        printf("** UNDERFLOW **\n");
    }
    struct Node *top = stack;
    int val = top->data;
    stack = top->next;
    free(top);
}

void printList(){
    struct Node *tmp = stack;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main(){
    stack = createNode(10);
    printList();
    printf("\n");
    push(5);
    printList();
    printf("\n");
    push(7);
    printList();
    printf("\n");
    push(8);
    printList();
    printf("\n");
    pop();
    printList();
    printf("\n");
}