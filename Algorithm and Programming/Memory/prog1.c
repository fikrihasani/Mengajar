#include <stdio.h>
#include <stdlib.h>

int main(){
    int * a;
    a = NULL;
    // set data dengan size 4
    a = (int *)malloc(4 * sizeof(int));
    a[0] = 10;
    a[1] = 5;
        free(a);
    printf("%d\n",a[0]);
    printf("%d\n",a[1]);

    if(a == NULL){
        printf("null");
    }
}