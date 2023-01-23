#include<stdio.h>
long long int totalLine = 100001;

int Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int FindMid(int low, int high, int arr[]){
	int pivot = arr[high];
	int point = low-1;
	for(int i=low; i<=high; i++){
		if(pivot>arr[i]){
			point++;
			Swap(&arr[i], &arr[point]);
		}
	}
	Swap(&arr[high], &arr[point+1]);
	return point+1;
}

int QuickSort(int low, int high, int arr[]){
	if(high>=low){
		int m = FindMid(low, high, arr);
		QuickSort(low, m-1, arr);
		QuickSort(m+1, high, arr);
	}
}

int main(){
	FILE *fp = fopen("prob2.txt", "r");
	int arr[totalLine];
	int count = 0;
	while(!feof(fp)){
		fscanf(fp, "%d", &arr[count]);
//		printf("%d\n", arr[count]);
		count++;
	}
	int low = 0, high = totalLine-1;
	QuickSort(low, high, arr);
//	for(int i = 0; i<totalLine; i++){
//		printf("%d\n", arr[i]);
//	}
	int Q1, Q2, Q3;
	int iQ1, iQ2, iQ3;
	int mQ1, mQ2, mQ3;
	
	// high = banyak data + 1
	if(high%2==0){
		iQ2 = high/2;
		Q2 = arr[iQ2];
		
		iQ1 = iQ2/2;
		int iQ12 = iQ1+1;
		Q1 = (arr[iQ1]+arr[iQ12])/2;
		
		iQ3 = iQ2+((high-iQ2)/2);
		int iQ32 = iQ3+1;
		Q3 = (arr[iQ3]+arr[iQ32])/2;
		
		mQ1 = (iQ1+iQ12)/2;
		mQ2 = iQ2;
		mQ3 = (iQ3+iQ32)/2; 
	}
	
	printf("Nilai Kuartil\nQ1: %d\nQ2: %d\nQ3: %d\n\n", Q1, Q2, Q3);
	printf("Index Quartil\nQ1: %d\nQ2: %d\nQ3: %d\n\n", mQ1, mQ2, mQ3);
	// printf("Index range for Q1\n\n");
	float rQ1=0, rQ2=0, rQ3=0;
	for(int i=0; i<mQ1; i++){
		// printf("Idx: %d\n", i);
		rQ1+=arr[i];
	}
	// printf("Index range for Q2\n\n");
	for(int i=mQ1; i<mQ2; i++){
		// printf("Idx: %d\n", i);
		rQ2+=arr[i];
	}
	// printf("Index range for Q3\n\n");
	for(int i=mQ2; i<mQ3; i++){
		// printf("Idx: %d\n", i);
		rQ3+=arr[i];
	}
	printf("Mean kuartil\nQ1: %.2f\nQ2: %.2f\nQ3: %.2f\n", rQ1/25000, rQ2/25000, rQ3/25000);
	fclose(fp);
}
