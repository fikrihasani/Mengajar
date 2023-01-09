#define MAX 1

#include <stdio.h>

int stack[MAX];

int topIdx;

void push(int val){
    if(topIdx == MAX - 1){
        return;
    }
    //increase topdx
    topIdx++;
    //insert ke ARRAY
    stack[topIdx] =val;
}

int pop(){
    if(topIdx == -1){
        return -1;
    }
    int val = stack[topIdx];
    stack[topIdx] = 0;

    topIdx--;
    return val;

}

int top(){
    return stack[topIdx];
}

void printStack(){
    for (int i = 0; i <= topIdx; i++)
    {
        /* code */
        printf("%d ",stack[i]);
    }
    printf("\n");
    
}

int main(){
    topIdx = -1;
    int val;
    push(10);
    push(5);
    printStack();
    val = pop();
    printf("%d\n",val);
    val = pop();
    printf("%d\n",val);
    printStack();

}