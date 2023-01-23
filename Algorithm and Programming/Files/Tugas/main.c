#include <stdio.h>
#include <stdlib.h>

struct dat
{
    /* data */
    int idx;
    int season;
    int ep;
    char epName[100];
    char name[26];
    char dialogue[500];
};



int main(){
    printf("Hello");
    FILE * fp = fopen("RickAndMortyScripts.csv","r");

    if (fp == NULL) {
        printf("Error: cannot open file");
        return 1;
    }else{
        printf("hello");
    }
    int i = 0;
    struct dat allDat[3000];
    printf("hello");
    char ss[1000];  
    fgets(ss,1000,fp);
    fgets(ss,1000,fp);
    printf("%s\n",ss);

    while(!feof(fp)){
        if(i == 2){
            break;
        }
        fscanf(fp,"%d;%d;%d;%[^;];%[^;];%[^\n]",&allDat[i].idx,&allDat[i].season,&allDat[i].ep,allDat[i].epName,allDat[i].name,allDat[i].dialogue);
        printf("%d\n",i);
        i++;
    }
    i = 200;
    printf("%d;%d;%d;%s;%s;%s\n",&allDat[i].idx,allDat[i].season,allDat[i].ep,allDat[i].epName,allDat[i].name,allDat[i].dialogue);
    fclose(fp);
    return 0;
}