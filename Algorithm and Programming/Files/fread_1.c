#include <stdio.h>

int main(){
    FILE *fp;
    int i;
    char ss[5][100];
    fp = fopen("lb01_5.dat","r");
    if(fp == NULL){
        return -1;
    }
    fread(ss,sizeof(char),sizeof(ss),fp);
    for(i = 0; i<5; i++){
        printf("%s\n",ss[i]);
    }
}