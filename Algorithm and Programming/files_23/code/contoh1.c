#include <stdio.h>

int main(){
    //char untuk simpan data kita. 
    char ch;
    //pointer file yang akan dipake
    FILE *fp;
    //nama filenya, terus modenya apa
    fp = fopen("../datas/data.txt","r");
    //ngecek apakah file bisa dibuka
    if(fp == NULL){
        printf("file tidak bisa dibuka/file tidak ada");
        return 0;
    }else{
    //kita baca karakter dari file pointer
        while (!feof(fp))
        {
            /* code */
            ch = fgetc(fp);
        //print karakternya
            printf("%c\n",ch);
        }
    }


    return 0;
}