#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node *next;
};


void printList(struct Node *n){
    while(n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
}

void createNode(int val, struct Node ** n){
    (*n) = (struct Node*)malloc(sizeof(struct Node)); 
    (*n)->data = val;
    (*n)->next = NULL;
}

void push(int val, struct Node ** n){
    struct Node *tmpNode; 
    struct Node *tmp = *n;
    createNode(val, &tmpNode);
    tmpNode->next = *n;
    (*n) = tmpNode;
}

int pop(struct Node **n){
    struct Node *top = *n;
    int val = top->data;
    *n = top->next;
    free(top);
    return val;
}


int main(){
    struct Node *n = NULL;
    char f[200];
    scanf("%s",&f);
    int i = 1;
    createNode(f[0]-'0',&n);
    int final = 0;
    while (f[i])
    {
        // push ke stack
        if (isdigit(f[i]))
        {
            /* code */
            push(f[i] - '0',&n);
        }
        else
        {
            // printf("sekarang: %c\n",f[i]);
            int a = pop(&n);
            int b = pop(&n);
            int x;
            // 56+
            // printf("%d dan %d\n",a,b);
            switch (f[i])
            {
            case '*'/* constant-expression */:
                /* code */
                x = b*a;
                printf("%d * %d = %d\n",b,a,x);
                push(x,&n);
                break;
            case '+'/* constant-expression */:
                /* code */
                x = b+a;
                printf("%d + %d = %d\n",b,a,x);
                push(x,&n);
                break;
            case '-'/* constant-expression */:
                /* code */
                x = b-a;
                printf("%d - %d = %d\n",b,a,x);
                push(x,&n);
                break;
            case '/'/* constant-expression */:
                /* code */
                x = b/a;
                printf("%d / %d = %d\n",b,a,x);
                push(x,&n);
                break;
            default:
                exit;
                break;
            }
        }
        i++;
        printList(n);
        printf("\n");
    }
    // printList(n);
    final = pop(&n);
    printf("%d",final);
    return 0;
}