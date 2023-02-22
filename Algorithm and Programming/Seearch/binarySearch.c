#include <stdio.h>

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
	}
	if (v[lo] == To_Find) {
		printf("Found At Index %d \n",lo);
	}
	else if (v[hi] == To_Find) {
		printf("Found At Index %d \n",hi);
	}
	else {
		printf("not found\n");
	}
}

int main()
{
    for(int i = 0; i<10; i++){
        printf("%d\n",rand()%20);
    }
	int v[] = { 1, 3, 4, 5, 6 };
    int hi = (int)sizeof(v)/sizeof(v[0]) -1;
	int To_Find = 1;
	binarySearch(v, hi, To_Find);
	To_Find = 6;
	binarySearch(v,hi, To_Find);
	To_Find = 10;
	binarySearch(v, hi,To_Find);
	return 0;
}
