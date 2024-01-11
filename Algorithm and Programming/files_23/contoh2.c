#include <stdio.h>

int main(){
    FILE * fp;
    char s[50] = "ini kalimat untuk ditulis\n";
    fp = fopen("data2.txt","a");
    if (fp == NULL)
    {
        /* code */
        printf("file cannot be created");
        return 0;
    }
    //write string to file
    fputs(s,fp);
    return 0;
}