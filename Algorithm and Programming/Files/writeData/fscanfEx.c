#include <stdio.h>

int main(){
    FILE *fp;

    int no[100];
    char name[100][20];
    float gpa[100];
    
    fp = fopen("data_1.txt","r");
    if(fp == NULL){
        printf("not exist");
        return -1;
    }
    int i = 0;
    while(fscanf(fp,"%d %s %f",&no[i],name[i],&gpa[i]) != -1){
        printf("%d %s %f\n",no[i],name[i],gpa[i]);
        i++;
    }
    fclose(fp);
    return 0;
}