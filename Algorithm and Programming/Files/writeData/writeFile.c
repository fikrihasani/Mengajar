#include <stdio.h>

int main(){
    FILE *fp = fopen("sample1.txt","w");
    if(fp == NULL){
        printf("could not open file");
        return -1;
    }else{
        for(int i = 96; i<125; i++){
            fprintf(fp,"%d is character %c\n",i,i);
        }
    }
    fclose(fp);
    return 0;
}