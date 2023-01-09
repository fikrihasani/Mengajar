#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * stack = NULL;

void printList(){
    struct Node *iter = stack;
    while(iter != NULL){
        printf("%d ", iter->data);
        iter = iter->next;
    }
    printf("\n");
}

struct Node * createNode(int val){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

void push(int val){
    struct Node * tmpNode = createNode(val); 
    tmpNode->next = stack;
    stack = tmpNode;
}

int pop(){
    struct Node * top = stack;
    int val = top->data;
    stack = top->next;
    free(top);
    return val;
}


int main(){
    char f[200];
    scanf("%s",&f);
    int i = 1;
    stack = createNode(f[0]-'0');
    int final = 0;
    while (f[i])
    {
        // push ke stack
        if (isdigit(f[i]))
        {
            /* code */
            push(f[i] - '0');
        }
        else
        {
            // printf("sekarang: %c\n",f[i]);
            int a = pop();
            int b = pop();
            int x;
            // 56+
            // printf("%d dan %d\n",a,b);
            switch (f[i])
            {
            case '*'/* constant-expression */:
                /* code */
                x = b*a;
                printf("%d * %d = %d\n",b,a,x);
                push(x);
                break;
            case '+'/* constant-expression */:
                /* code */
                x = b+a;
                printf("%d + %d = %d\n",b,a,x);
                push(x);
                break;
            case '-'/* constant-expression */:
                /* code */
                x = b-a;
                printf("%d - %d = %d\n",b,a,x);
                push(x);
                break;
            case '/'/* constant-expression */:
                /* code */
                x = b/a;
                printf("%d / %d = %d\n",b,a,x);
                push(x);
                break;
            default:
                exit;
                break;
            }
        }
        i++;
        printList();
        printf("\n");
    }
    // printList(n);
    final = pop();
    printf("%d",final);
    return 0;
}