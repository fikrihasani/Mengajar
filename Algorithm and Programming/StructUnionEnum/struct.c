#include <stdio.h>

struct data{
    int a;
    int b;
};

int main(){
    struct data c;
    c.a = 10;
    c.b = 15;
    printf("%d %d", c.a, c.b);
    return 0;
}