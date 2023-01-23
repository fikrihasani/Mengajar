#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 26
int main(){
    int value;
    int key;
    long long int hashed;
    char buffer[50];
    sprintf(buffer,"%lld",99*99);
    printf("%s\n",buffer);
    char keyS[25] = "";
    if(strlen(buffer)%2 == 1){
        int mid = strlen(buffer)/2;
        strncat(keyS,&buffer[mid],1);
    }else{
        // only fet 2 character
        int mid = strlen(buffer)/2 - 1;
        strncat(keyS,&buffer[mid],1);
        strncat(keyS,&buffer[mid+1],1);
    }
    char *strBuff;
    printf("%s\n",keyS);
    // strtol solution
    // hashed = strtol(keyS,&strBuff,10);
    // sscanf solution
    sscanf(keyS,"%lld",&hashed);
    printf("%lld",hashed+1);

    // division
    hashed = hashed % SIZE;
    // printf("%s",strBuff);
    return 0;
}