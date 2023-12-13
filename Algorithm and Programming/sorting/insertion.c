#include <stdio.h>

int main(){
    int arr[] = {9,2,10,7,4,1,3};

    int n = sizeof(arr)/sizeof(arr[0]);
    
    for (int i = 0; i < n-1; i++)
    {
        /* code */
        for (int j = i+1; j < n; j++)
        {
            /* code */
            if(arr[j] < arr[i]){
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
        for(int i= 0; i < n; i++){
            printf("%d ",arr[i]);

        }
    
    return 0;

}