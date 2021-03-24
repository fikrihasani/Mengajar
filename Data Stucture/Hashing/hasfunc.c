#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 26

int midSquare(int key){
    int square = key*key;
    char digit[1000];
    sprintf(digit, "%d",square);
}

int division(int key){
    return key % size;
}

int stringToKey(char s[]){
    int tot = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        /* code */
        tot = tot + s[i];
    }
    return tot;
}


int main(){
    // char *key;
    // gets(key);
    // char key[20];
    // printf("Enter something\n");
    int key;
    key = stringToKey("cobb");
    int hashVal = division(key);
    printf("%d\n",key);
    printf("%d",hashVal);
    // Here \n indicates that; take the input
    // until newline is encountered
    // scanf("%[^\n]s", key); 
    // printf("%s\n", key);
    // printf("%d\n",strlen(key));
    // int intKey;
    // intKey = atoi(key);
    // printf("%d",intKey);
    return 0;
}