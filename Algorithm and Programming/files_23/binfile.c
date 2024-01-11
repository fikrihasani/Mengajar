#include <stdio.h>

int main(){
    FILE * fp;
    int dat[] = {1,2,3};
    fp = fopen("datas.dat","wb");
    fwrite(dat,4,3,fp);
    fclose(fp);
    return 0;
}