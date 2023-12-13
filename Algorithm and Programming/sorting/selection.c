#include <stdio.h>

int main(){
    int arr[] = {9,2,10,7,4,1,3};

    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i= 0; i < n-1; i++){
        //
        int tmp = i;
        for(int j = i+1;j < n;j++){
            if(arr[tmp] > arr[j]){
                tmp = j;
            }
        }
        //tuker
        int tmpv = arr[tmp];
        arr[tmp] = arr[i];
        arr[i] = tmpv;
    }
    
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d ",arr[i]);
    }
    
    return 0;

}