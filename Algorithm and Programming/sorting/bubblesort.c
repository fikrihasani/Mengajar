#include <stdio.h>

int main(){
    int arr[] = {9,2,10,7,4,1,3};

    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[j] < arr[j-1]){
                int tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}