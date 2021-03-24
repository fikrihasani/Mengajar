#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10

struct Node{
    int val;
    char name[20];
    struct Node *next;
} *table[size], *node;

int hash(char name[]){
    return (name[0] - 'A')%size;
}

void insertTable(char name[]){
    int hashVal = hash(name);

    node = (struct Node *)malloc(sizeof(struct Node));
    node->val = hashVal;
    strcpy(node->name, name);
    node->next = NULL;

    if (table[hashVal] != NULL)
    {
        /* code */
        struct Node *curr = table[hashVal];
        while (curr->next != NULL)
        {
            /* code */
            curr = curr->next;
        }
        
        curr->next = node;
    }else{
        table[hashVal] = node;
    }
}

void printData(){
    for (int i = 0; i < size; i++)
    {
        /* code */
        if (table[i] != NULL)
        {
            /* code */
            printf("%d ||",i);
            struct Node *curr = table[i];
            while (curr!= NULL)
            {
                /* code */
                printf("%s ",curr->name);
                if (curr->next != NULL)
                {
                    /* code */
                    printf("->");
                }
                curr = curr->next;
            }
            printf("\n");
        }
        
    }
    
}

int main(){
    char nama[20];
    do
    {
        gets(nama);
        insertTable(nama);
        system("cls");
        printData();
        /* code */
    } while (1);
    return 0;
}

