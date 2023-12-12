#include <stdio.h>
#include <string.h>

int main(){
    union data
    {
        /* data */
        int a;
        int b;
        char x[50];
    } data1;

    data1.a = 10;
    data1.b = 500;
    strcpy(data1.x,"kata");

    printf("a: %d\n",data1.a);
    printf("b: %d\n",data1.b);
    printf("c: %s\n",data1.x);

    return 0;
    
}