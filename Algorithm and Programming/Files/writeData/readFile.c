#include <stdio.h>

int main () {
    FILE *fp; int i;
    int Arr[5];
    fp=fopen("test.dat","r");
    if(fp==NULL){
        printf("File test.dat can’t be opened\n");
        return (1);
    }
    fread(Arr,sizeof(Arr),sizeof(Arr),fp);
    for(i=0; i<5; i++) printf("%d ",Arr[i]);
    fclose(fp);
}