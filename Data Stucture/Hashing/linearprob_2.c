#define MAXSIZE 5
#include <string.h>
#include <stdio.h>

char hashTable[MAXSIZE][50];

int hashing(char s[]){
    return s[0]-'a';
}

void initTable(){
    int i;
    for (i = 0; i < MAXSIZE; i++)
    {
        /* code */
        // hashTable[i] = NULL;
        strcpy(hashTable[i],"");
    }
    
}

void delete(int key){
    strcpy(hashTable[key],"");
}

void insert(char s[]){
    int key = hashing(s)%MAXSIZE;
    //masih kosong, insert
    if(strcmp(hashTable[key],"") == 0){
        strcpy(hashTable[key],s);
    }else
    {
        int i = (key+1) % MAXSIZE;
        while (strcmp(hashTable[i],"") != 0 && i != key)
        {
            i++;
            if (i == MAXSIZE)
            {      
                i = i % MAXSIZE;
            }

        }
        if (i == key)
        {
            printf("table penuh\n");
            return;
        }
        strcpy(hashTable[i],s);
        return;      
    }
}

void print(){
    int i;
    for (i = 0; i < MAXSIZE; i++)
    {
        /* code */
        if (strcmp(hashTable[i],"") != 0)
        {
            /* code */
            printf("%d -> %s\n",i,hashTable[i]);
        }
    }
    
}
int main(){
    char s[50];
    initTable();  
    int i = 0;
    for (i = 0; i < 6; i++)
    {
        /* code */
        scanf("%s",s);
        insert(s);
        print();
    }
    

}