#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 8

// array of string dengan ukuran 8
char data[size][12];

int hashing(char c){
    // dapat hash value 
    // fungsi karakter pertama di string
    return (c - 'a')%size;
}

void initTable(){
    for (int i = 0; i < size; i++)
    {
        // inisiasi array dengan empty string
        strcpy(data[i],"");
    }
}

void printData(){
    for (int i = 0; i < size; i++)
    {
        if (strcmp(data[i],"")!=0)
        {
            /* code */
            printf("%d || %s\n",i,data[i]);
        }
        
        /* code */
    }
    
}

int main(){
    // var string
    char name[12];
    // var untuk menyimpan hasil hashing
    int key;
    // hashing fungtion 

    // cek apakah posisi array pada hashVal
    while(1){
        scanf("%s",&name);
        key = hashing(name[0]);
        if(strcmp(data[key],"") == 0){
            // insert string ke posisi key
            strcpy(data[key],name);
        }else{
            // ada isinya
            // lakukan linear probing
            int iter = (key + 1)%size;
            // check jika array full
            int full = 0;
            while(strcmp(data[iter],"")!=0){
                // jika dia sudah berputar dan  kembali ke nilai awal
                if(iter == key){
                    printf("data full\n");
                    full = 1;
                    break;
                }
                // berjalan di arraynya
                iter = (iter+1)%size;
            }
            if(!full){
                strcpy(data[iter],name);
            }
        }
        printData();
    }
    return 0;
}

