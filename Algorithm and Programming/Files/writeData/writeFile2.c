#include <stdio.h>

int main(void) 
{
    FILE *fp; 
    int Arr[]={1,2,3,4,5};
    fp=fopen("test.txt","w");
    if(fp==NULL){
        printf("File test.dat can’t be created\n");
        return -1;
    }
    fwrite(Arr,sizeof(Arr),sizeof(Arr),fp);
    fclose(fp);
    return 0;
}
