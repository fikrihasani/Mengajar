#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    /* data */
    int val;
    struct node *next;
};

struct node * stack = NULL;

void printStack(){
    struct node * iter = stack;
    while(iter){
        printf("%d ",iter->val);
        iter = iter->next;
    }
    printf("\n");
}

struct node * createNode(int val){
    struct node * tmp = (struct node *)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;
}

void push(int val){
    struct node * tmp = createNode(val);
    tmp->next = stack;
    stack = tmp;
}

int pop(){
    struct node * tmp = stack;
    int val = tmp->val;
    stack = tmp->next;
    free(tmp);
    return val;
}

int main(){
    // variable untuk menyimpan notasi yang dimasukkan
    char s[100];
    scanf("%s",s);
    int i = 1;
    // create stack from first character
    stack = createNode(s[0]-'0');
    // final value
    int final = 0;
    while(s[i]){
        // push jika digit
        if(isdigit(s[i])){
            push(s[i]-'0');
        }else{
            // pop dan push jika operator
            int a = pop();
            int b = pop();
            int x;
            //mengecek operator apa saat ini
            switch (s[i])
            {
            case '*':
                /* code */
                x = b*a;
                push(x);
                break;
            
            case '+':
                /* code */
                x = b+a;
                push(x);
                break;
            
            case '-':
                /* code */
                x = b-a;
                push(x);
                break;
            case '/':
                /* code */
                x = b/a;
                push(x);
                break;
            
            default:
                break;
            }
        }
        i++;
    }
    final = pop();
    printf("%d",final);
    return 0;
}