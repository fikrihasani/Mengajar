#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int arr[], int L, int R){
    int j, k;
    if(L < R){
        j = L; 
        k = R+1;
        printf("j: %d, k: %d\n",j,k);
        do
        {
            do
            {
                j+=1;
            } while (arr[j] < arr[L]);
            do
            {
                k -=1;
            } while (arr[k] > arr[L]);
            if (j < k)
            {
                swap(&arr[j],&arr[k]);
            } 
            printf("j: %d, k: %d\n",j,k);
        } while (j<=k);
        printf("j: %d, k: %d\n",j,k);
        swap(&arr[L],&arr[k]);
        quicksort(arr,L,k-1);
        quicksort(arr,k+1,R);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* Driver code */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 , 7, 8};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	quicksort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}