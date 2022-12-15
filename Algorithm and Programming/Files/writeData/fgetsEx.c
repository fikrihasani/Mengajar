#include <stdio.h>
#include <string.h>

int main(){
    //inisiasi variable file
    FILE *fp;
    //kita inisasi variable string untuk menyimpan data kita
    char ss[80];
    //membuka file
    fp = fopen("lh01_1.txt","r");
    //cek apakah file ada
    if(fp == NULL){
        return -1;
    }
    //read for every line. 
    while(fgets(ss,80,fp)){
        printf("%s\n",ss);
    }
    fclose(fp);
    return 0;
}