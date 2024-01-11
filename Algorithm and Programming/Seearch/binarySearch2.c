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
		if (v[mid] > To_Find) {
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
	for(int i = 0; i < Q; i++){
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i < Q; i++){
		scanf("%s",names[i]);
	}
	scanf("%d",&noQ);

    int hi = Q-1;
	int To_Find = noQ;
	int idx = binarySearch(arr, hi, To_Find);
	int range = Q/4;
	int firstPart1 = 0;
	int firstPart2 = firstPart1 + range -1;
	int secPart1 = firstPart2 + 1;
	int secPart2 = secPart1 + range - 1;
	int thirdPart1 = secPart2 + 1;
	int thirdPart2 = thirdPart1 + range - 1;
	int fourthPart1 = thirdPart2 + 1;
	int fourthPart2 = fourthPart1 + range - 1;
	// printf("range: %d\nfirstpart1: %d\nfirstpart2: %d\nsecondpart1: %d\nsecondpart2: %d\nthirdpart1: %d\nthirdpart2: %d\nfourthpart1: %d\nfourthpart2: %d\n", range, firstPart1, firstPart2, secPart1, secPart2, thirdPart1, thirdPart2, fourthPart1, fourthPart2);
	int part = 0;
	if(idx >= firstPart1 && idx <= firstPart2) part = 1;
	else if (idx >= secPart1 && idx <= secPart2) part = 2;
	else if (idx >= thirdPart1 && idx <= thirdPart2) part = 3;
	else if (idx >= fourthPart1 && idx <= fourthPart2) part = 4;
	else part = -1;
	if(idx == -1) printf("%d %s %d\n",-1,"null",-1);
	else printf("%d %s %d\n",idx,names[idx],part);
	return 0;
}
