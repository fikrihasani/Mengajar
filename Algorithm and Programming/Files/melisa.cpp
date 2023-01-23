#include<stdio.h>

void merge(int arr[], int left, int right){
	int mid=(left+right)/2;
	int leflen=mid-left+1;
	int rightlen=right-mid;
	
	int leftarr[leflen], rightarr[rightlen];
	for(int i=0; i<leflen; i++){
		leftarr[i]=arr[i+left];
	}
	for(int j=0; j<rightlen; j++){
		rightarr[j]=arr[mid+1+j];
	}
	
	int maincursor=left;
	int leftcur=0, rightcur=0;
	while(leftcur<leflen && rightcur<rightlen){
		if(leftarr[leftcur]<=rightarr[rightcur]){
			arr[maincursor++]=leftarr[leftcur++];
		}
		else{
			arr[maincursor++]=rightarr[rightcur++];
		}
	}
	
	while(leftcur<leflen){
		arr[maincursor++]=leftarr[leftcur++];
	}
	
	while(rightcur<rightlen){
		arr[maincursor++]=rightarr[rightcur++];
	}
}

void sort(int arr[], int left, int right){
	if(left>=right) return;
	
	int mid=(left+right)/2;
	sort(arr, left, mid);
	sort(arr, mid+1, right);
	merge(arr, left, right);
}

int main(){
	int angka[100000];
	FILE *fp=fopen("prob2.txt", "r");
	int i=0;
	while (true){
		fscanf(fp, "%d", &angka[i]);
		if(feof(fp)) break;
		i++;
	}
	
	sort(angka, 0, i);
	for(int j=0; j<i; j++){
		printf("%d\n", angka[j]);
	}
	
	int avg=0, kur=0;
	int tengah=i/2-1;
	for(int j=tengah; j<i; j++){
		avg+=angka[j];
		kur++;
	}
	int top=avg/kur;
	printf("%d\n", top);
	
	fclose(fp);
	return 0;
}
