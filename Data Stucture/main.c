#include <stdio.h>
//inisiasi

int find(int a[5], int bil) {
	int found = 0;
	int i = 0;

	while(!found && i<5){
		if(a[i] == bil){
			found = 1;
		}
		i++;
	}
	
   return found;
}

int main () {

   /* global variable definition */
   //inisialisasi array
	int a[5] = {0,1,2,3,4};
	int bil = 3;
	
	int found = find(a,bil);
	if(found){
		printf("FOUND");
	}else{
		printf("NOT FOUND");
	}
   return 0;
}




