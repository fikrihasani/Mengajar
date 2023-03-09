#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


struct Node{
    double data;
    struct Node *next;
};

struct Node * stack = NULL;

void printList(){
    struct Node *iter = stack;
    while(iter != NULL){
        printf("%.2lf", iter->data);
        iter = iter->next;
    }
    printf("\n");
}

struct Node * createNode(double val){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

void push(double val){
    struct Node * tmpNode = createNode(val); 
    tmpNode->next = stack;
    stack = tmpNode;
}

double pop(){
    struct Node * top = stack;
    double val = top->data;
    stack = top->next;
    free(top);
    return val;
}


int main(){
    char f[200];
    scanf("%s",f);
    int i = 1;
    stack = createNode(f[0]-'0');
    double final = 0;
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
            double a = pop();
            double b = pop();
            double x;
            // 56+
            // printf("%.2lf dan %.2lf\n",a,b);
            switch (f[i])
            {
            case '*'/* constant-expression */:
                /* code */
                x = b*a;
                printf("%.2lf * %.2lf = %.2lf\n",b,a,x);
                push(x);
                break;
            case '+'/* constant-expression */:
                /* code */
                x = b+a;
                printf("%.2lf + %.2lf = %.2lf\n",b,a,x);
                push(x);
                break;
            case '-'/* constant-expression */:
                /* code */
                x = b-a;
                printf("%.2lf - %.2lf = %.2lf\n",b,a,x);
                push(x);
                break;
            case '/'/* constant-expression */:
                /* code */
                x = b/a;
                printf("%.2lf / %.2lf = %.2lf\n",b,a,x);
                push(x);
                break;
            case '^'/* constant-expression */:
                /* code */
                x = pow(b,a);
                printf("%.2lf ^ %.2lf = %.2lf\n",b,a,x);
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
    printf("%.2lf",final);
    return 0;
}