#include <stdio.h>

struct data
{
    /* data */
    int val;
};

int main(){
    int size = 5;
    struct data bio[size];
    for (int i = 0; i < size; i++)
    {
        /* code */
        bio[i].val = i;
    }

    for (int i = 0; i < size; i++)
    {
        /* code */
        printf("%d ",bio[i].val);
    }
    
    return 0;
}