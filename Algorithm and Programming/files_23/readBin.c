#include <stdio.h>

int main(){
    FILE * fp;
    int dat[3];
    fp = fopen("datas.dat","rb");
    fread(dat,4,3,fp);
    for(int i = 0; i < 3; i++){
        printf("%d\n",dat[i]);
    }
    fclose(fp);
    return 0;
}   