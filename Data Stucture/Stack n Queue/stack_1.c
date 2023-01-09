#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct node
{
    /* data */
    int val;
    struct node * next;
};

struct node * stack = NULL;

int countEl = 0;

struct node * createNode(int val){
    struct node * tmp = (struct node *)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;
    return tmp;
}

void push(int val){
    countEl++;
    if(stack == NULL){
        stack = createNode(val);
    }else{
        struct node * tmp = createNode(val);
        tmp->next = stack;
        stack = tmp;
    }
}

void printStack(){
    struct node * iter = stack;
    while(iter){
        printf("%d ",iter->val);
        iter = iter->next;
    }
    printf("\n");
}

struct node * pop(){
    if(!stack){
        struct node *tmp = NULL;
        return tmp;
    }
    //get top of stack
    struct node * delNode = stack;
    //copy value of top stack
    struct node * tmp = createNode(delNode->val);
    //delete top stack
    stack = delNode->next;
    free(delNode);
    //return top stack 
    return tmp;
}

struct node * top(){
    struct node * tmp = stack;
    return tmp;
}

int isFull(){
    // struct node * iter = stack;
    // int jumlah = 0;
    // while(iter){
    //     jumlah++;
    //     iter = iter->next;
    // }
    if(countEl == MAX){
        return 1;
    }
    return 0;
}

int main(){
    push(10);
    push(5);
    push(5);
    push(5);
    push(5);

    printStack();
    printf("%d",isFull());
    // struct node * topDat = top();
    // printf("top data: %d\n",topDat->val);
    // struct node * popped = pop();
    // printStack();
    // if(popped) printf("popped data: %d\n",popped->val);
    // popped = pop();
    // printStack();
    // if(popped) printf("popped data: %d\n",popped->val);
    // popped = pop();
    // if(popped) printf("popped data: %d\n",popped->val);
}