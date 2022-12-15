#include <stdio.h>

int main(){
    //disini inisiasi variable file
    FILE *fp;
    //inisiasi variable yang akan disimpan
    char s[100];
    //open file by location
    fp = fopen("../lb01_1.txt","r");
    if(fp == NULL){
        return -1;
    }
    while (fgets(s,100,fp))
    {
        /* code */
        printf("%s",s);
    }
    fclose(fp);
    return 0;
    


}