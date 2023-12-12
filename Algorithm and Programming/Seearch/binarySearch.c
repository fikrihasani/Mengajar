#include <stdio.h>

int search(int data[], int l, int r, int target){
	while(l <= r){
		int m = (l+r)/2;

		if(data[m] == target){
			return m;
		}

		if(data[m] > target){
			r = m-1;
		}

		if(data[m] < target){
			l = m+1;
		}
	}
	return -1;
}


int main(){
	int data[] = {4,6,8,14,15,16,17,18,19,20};
	int target = 1;
	int idx = search(data, 0,9,target);
	printf("%d\n",idx);
	return 0;

}