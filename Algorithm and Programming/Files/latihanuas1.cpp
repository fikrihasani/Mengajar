#include<stdio.h>
#include<string.h>
int n=100;

struct type{
	char s[1000];
	long long a=0;
};

int main(){
	FILE *fp;
	fp=fopen("prob3SortNumChar.txt","r");
	type b[n];
	for(int i=0;i<n;i++){
		fscanf(fp,"%s",b[i].s);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<strlen(b[i].s);j++){
			if(j==0){
				b[i].a+=(b[i].s[j]-'0');
			}else{
				b[i].a-=(b[i].s[j]-'0');
			}
		}
	}

	// INSERT SORT
	for(int i=1;i<n;i++){
		int k=i;
		while(k!=0&&b[k-1].a<b[k].a){
			type tmp=b[k];
			b[k]=b[k-1];
			b[k-1]=tmp;
			k--;
		}
		// JIKA NILAI SAMA MAKA URUT BY STRINGNYA DENGAN STRCMP
		while(k!=0&&b[k-1].a==b[k].a&&strcmp(b[k].s,b[k-1].s)>0){
			type tmp=b[k];
			b[k]=b[k-1];
			b[k-1]=tmp;
			k--;
		}
	}
	for(int i=0;i<n;i++){
		printf("%lld \t%s\n",b[i].a,b[i].s);
	}
	
	return 0;
}


//'x'-'0' = x
