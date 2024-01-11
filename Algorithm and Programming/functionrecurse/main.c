#include <stdio.h>

void change(int data[], int val, int count){
    for (int i = 0; i < count; i++)
    {
        /* code */
        data[i]+=val;
    }
    
}

void print(int data[], int count){
    for (int i = 0; i < count; i++)
    {
        /* code */
        printf("%d ",data[i]);
    }
    printf("\n");
}
int main(){
    int data[] = {1,2,3,4};
    print(data,4);
    change(data, 1, 4);
    print(data,4);
    return 0;
}
