#include <stdio.h>
#include <string.h>

int main(){
    //inisiasi variable fp
    FILE *fp;
    //var yang akan kita tulis
    char ss[80] = "this is statement that will be written";
    // i sebagai iterator untuk menulis data
    fp = fopen("lh01_1.txt","w");
    if(fp == NULL){
        printf("file can't be crated\n");
        return -1;
    }
    for(int i = 0; i<strlen(ss);i++){
        fputc(ss[i],fp);
    }
    return 0;
}