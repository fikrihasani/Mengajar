#include <stdio.h>
#include <string.h>

// fputs untuk write string datas to file

int main(){
    FILE *fp;
    int inp = 1;
    char ss[5][100];
    strcpy(ss[0],"String 1");
    strcpy(ss[1],"String 2");
    strcpy(ss[2],"String 3");
    strcpy(ss[3],"String 4");
    strcpy(ss[4],"String 5");
    fp = fopen("lb01_3.txt","w");
    if(fp == NULL){
        return -1;
    }
    // fputs(ss,fp);
    for(int i = 0; i<5; i++){
        fprintf(fp,"%s\n",ss[i]);
    }
    fclose(fp);
    return 0;
}