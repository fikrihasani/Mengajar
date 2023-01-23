#include<stdio.h>
#include<stdlib.h>
long long int totalLine = 100001;

int BinarySearch(int low, int high, int find, int arr[]){
	int mid=(high+low)/2;
	if(high>=low){
		if(find == arr[mid]) return mid;
		if(find > arr[mid]) return BinarySearch(mid+1, high, find, arr);
		else return BinarySearch(low, mid-1, find, arr);
	}else return -1;
}
int main(){
	// baca filenya
	FILE *fp = fopen("items.txt", "r");
	int arr[totalLine];
	int count=0;
	// read data to array
	while(!feof(fp)){
		fscanf(fp, "%d\n", &arr[count]);
		// increase row number
		count++;
	}
	int low = 0, high = totalLine-1;
	int find;
	scanf("%d", &find); getchar();
	// using binary search
	int ind = BinarySearch(low, high, find, arr);
	
	if(ind!=-1)	printf("Found in index: %d\n", ind);
	else printf("Not found!\n%d\n", ind);
	fclose(fp);
	
}
