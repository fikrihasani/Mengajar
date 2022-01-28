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
    return (name[0] - 'a')%size;
}

void insertTable(char name[]){
    // hashing dulu
    int hashVal = hash(name);
    printf("hasil hashing: %d\n",hashVal);
    
    // init node
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

int search(char key[]){
    // logic traversal pada looping
    int hashVal = hash(key);
    // jika hashfunc itu menggunakan char pertama
    if (strcmp(table[hashVal]->name,key) == 0)
    {
        /* code */
        return 1;
    }else{
        //loop ke belakang
        struct Node *curr = table[hashVal];
        while (curr->next != NULL &&  strcmp(table[hashVal]->name,key)==0)
        {
            /* code */
            curr = curr->next;
        }
        return 1;
    }
    
    return -1;
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
        // system("cls");
        printData();
        /* code */
    } while (1);
    return 0;
}

