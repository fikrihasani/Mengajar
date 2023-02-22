#define MAXSIZE 5
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    /* data */
    char s[50];
    struct node *next;
} * hashTable[MAXSIZE];

void initTable(){
    int i;
    for ( i = 0; i < MAXSIZE; i++)
    {
        /* code */
        hashTable[i] = NULL;
    }
    
}

int hashing(char s[]){
    return s[0]-'a';
}

void print(){
    int i;
    for (i = 0; i < MAXSIZE; i++)
    {
        /* code */
        if (hashTable[i]!=NULL)
        {
            /* code */
            printf("%d -> ",i);
            struct node * iter = hashTable[i];
            while (iter)
            {
                /* code */
                printf("%s ",iter->s);
                iter = iter->next;
            }
            printf("\n");
        }
        

        
    }
    
}

void insert(char s[]){
    int key = hashing(s) %MAXSIZE;
    if (hashTable[key] == NULL)
    {
        /* code */
        hashTable[key] = (struct node *)malloc(sizeof(struct node));
        strcpy(hashTable[key]->s,s);
        hashTable[key]->next = NULL;
    }else
    {
        /* code */
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        strcpy(tmp->s,s);
        tmp->next = NULL;

        struct node *iter = hashTable[key];
        while (iter->next != NULL)
        {
            /* code */
            iter = iter->next;
        }
        iter->next = tmp;
    }    
}

int main(){
    char s[50];
    int i;
    for (i = 0; i < 6; i++)
    {
        /* code */
        scanf("%s",s);
        insert(s);
        print();
    }
    return 0;
}
