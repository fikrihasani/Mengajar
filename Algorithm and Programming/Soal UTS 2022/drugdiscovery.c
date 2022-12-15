#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int T;
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++){
		int N;
		int count = 0;
		// scanf("%d", &N);
		char arr[1000];
        scanf("%s",arr);
        printf("Case %d: ", i+1);
		for(int k = 0; arr[k] != '\0'; k++){
			if(arr[k] == arr[k+1]){
                printf("%c",arr[k]);
				count++;
				k++;
			}
		}
		if(count == 0)	
		    printf("N/A");
        printf("\n");
	}
}