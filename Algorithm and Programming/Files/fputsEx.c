#include <stdio.h>
#include <string.h>

// fputs untuk write string datas to file

int main(){
    FILE *fp;
    int inp = 1;
    char ss[5][100];
    strcpy(ss[0],"String 1\n");
    strcpy(ss[1],"String 2\n");
    strcpy(ss[2],"String 3\n");
    strcpy(ss[3],"String 4\n");
    strcpy(ss[4],"String 5\n");
    fp = fopen("lb01_2.txt","w");
    if(fp == NULL){
        return -1;
    }
    // fputs(ss,fp);
    for(int i = 0; i<5; i++){
        fputs(ss[i],fp);
    }
    fclose(fp);
    return 0;
}