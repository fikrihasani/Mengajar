#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySearch(int v[], int hi, int To_Find)
{
	int lo = 0;
	int mid;
	// This below check covers all cases , so need to check
	// for mid=lo-(hi-lo)/2
	while (hi - lo > 1) {
		int mid = (hi + lo) / 2;
		if (v[mid] < To_Find) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
		// printf("lo: %d - mid: %d - hi: %d\n",lo, mid, hi);
	}
	if (v[lo] == To_Find) {
		// printf("Found At Index %d \n",lo);
		return lo;
	}
	else if (v[hi] == To_Find) {
		// printf("Found At Index %d \n",hi);
		return hi;
	}
	else {
		// printf("not found\n");
		return -1;
	}
}
int main()
{
	int Q, noQ;
	scanf("%d",&Q);
	int arr[Q];
	char names[Q][10];
	char name[10];
	for(int i = 0; i < Q; i++){
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i < Q; i++){
		scanf("%s",names[i]);
	}
	scanf("%d %s",&noQ,name);

    int hi = Q-1;
	int To_Find = noQ;
	int idx = binarySearch(arr, hi, To_Find);
	printf("position: %d",idx+1);
	if(idx == 0){
		printf("null %s\n",names[idx+1]);
	}else if (idx == Q-1){
		printf("%s null\n",names[idx-1]);
	}else{
		printf("%s %s\n",names[idx-1],names[idx+1]);
	}
	return 0;

}