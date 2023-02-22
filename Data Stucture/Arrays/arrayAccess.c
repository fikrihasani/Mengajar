#include <stdio.h>
#include <stdlib.h>

void changeArr(int arr[]){
    arr[0] = 1000;
}
int main(){
    int arr[] = {5,9,10,11,12};
    for(int i = 0; i<sizeof(arr)/sizeof(arr[0]);i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int i = 0; i<sizeof(arr)/sizeof(arr[0]);i++){
        printf("%d ",*(arr+i));
    }
    printf("%d\n",*arr);
    printf("%d\n",*(arr+1));

    return 0;
}