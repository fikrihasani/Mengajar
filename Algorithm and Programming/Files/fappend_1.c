#include <stdio.h>

int main(){
    FILE *fp;
    fp = fopen("lb01_4.txt","a");
    if(fp == NULL){
        return -1;
    }
    fprintf(fp,"%s,%d","Cardcaptor Sakura Season 2",90);
    fclose(fp);
    return 0;
}