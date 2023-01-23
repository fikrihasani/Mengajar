#include <stdio.h>
#include <string.h>


int hashFunc(char value[]){
    return value[0]-'a';
}


char hashTable[26][26];

void initTable(){
    for (int i = 0; i < 26; i++)
    {
        /* code */
        strcpy(hashTable[i],"");
    }   
}

void printTable(){
    for(int i = 0; i<26;i++){
        if(hashTable[i][0] != '\0'){
            printf("%s\n",hashTable[i]);
        }
    }
}

int main(){
    char s[26];
    scanf("%s",s);
    int key = 0;
    key = hashFunc(s);
    strcpy(hashTable[key],s);
    scanf("%s",s);
    key = hashFunc(s);
    strcpy(hashTable[key],s);
    printTable();
    return 0;
}