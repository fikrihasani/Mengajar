#include <stdio.h>
#include <stdlib.h>

#define node 5

int g[node][node];

int main(){
    g[0][1] = 10;
    printf("%d\n",g[0][1]);
}