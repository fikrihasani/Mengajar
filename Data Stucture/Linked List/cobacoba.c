#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10

struct Node{
    int hashVal;
    char name[20];
    struct Node *next;
    struct Node *subHash[size];
} *table[size], *node;

struct lNode{
    char nameDir[20];
    struct lNode *next;
} *tmpLL;



struct lNode * createlNode(char nameDir[20]){
    struct lNode *tmp;
    tmp = (struct lNode *)malloc(sizeof(struct lNode));
    strcpy(tmp->nameDir,nameDir);
    tmp->next = NULL;
    return tmp;
}

void insertTmpLL(char namedir[20]){
    // create node
    struct lNode * tmp= createlNode(namedir);

    // check node
    if(tmpLL == NULL){
        tmpLL = tmp;
    }else{
        struct lNode *iter = tmpLL;
        while (iter->next != NULL)
        {
            /* code */
            iter = iter->next;
        }
        iter->next = tmp;        
    }
}

void printTmpLL(){
    struct lNode *iter = tmpLL;
    while (iter != NULL)
    {
        printf("%s - ",iter->nameDir);
        /* code */
        iter = iter->next;
    }
    printf("\n");
}

// calculate hash
int hash(char name[]){
    int hashed = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        /* code */
        hashed = name[i]-'a';
    }
    hashed = hashed % 10;
    return hashed;
}

void insertTable(char name[], struct Node * table[]){


    // hashing dulu
    int hashVal = hash(name);
    // printf("hasil hashing: %d\n",hashVal);
    
    node = (struct Node *)malloc(sizeof(struct Node));
    node->hashVal = hashVal;
    strcpy(node->name, name);
    node->next = NULL;

    // insert ke dalam yang sudah ada isi
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

int search(char key[], struct Node * table[]){
    // logic traversal pada looping
    int hashVal = hash(key);
    if (table[hashVal] == NULL)
    {
        /* code */
        return -1;
    }
        
    // jika hashfunc itu menggunakan char pertama
    if (strcmp(table[hashVal]->name,key) == 0)
    {
        /* code */
        return hashVal;
    }else{
        //loop ke belakang
        struct Node *curr = table[hashVal];
        while (curr->next != NULL &&  strcmp(table[hashVal]->name,key)==0)
        {
            /* code */
            curr = curr->next;
        }
        return hashVal;
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

// untuk mencari apakah data nya itu ada di dalam array. loop ke nested array of hash chain
void searchNested(struct Node * table[]){
    struct lNode  * tmp = tmpLL;
    while (tmp->next!= NULL)
    {
        // pop LL 
        if (search(tmp->nameDir,table) != -1)
        {
            // remove inside LL
            tmpLL = tmpLL->next;
            free(tmp);
            tmp = tmpLL;
            // recurse ke belakang
            table = table[hash(tmp->nameDir)]->subHash;
        }else{
            printf("tidak ada direktori\n");
            return;
        }
    }
    insertTable(tmp->nameDir,table);
}

int main(){
    char nama[20];
    char command[10];
    char type[20];
    scanf("%s %s",&command,&type);
    if (strcmp("create",command) == 0)
    {
        /* code */
        char namedir[50];
        // scanf("%s",&namedir);
        strcpy(namedir,"home/");
        char *token;
    
        /* get the first token */
        token = strtok(namedir,"/");
        
        /* walk through other tokens */
        int count = 0;
        while( token != NULL ) {
            count++;
            // insert 
            insertTmpLL(token);            
            token = strtok(NULL, "/");
        }
        // cek apakah ada sub dir
        if (count == 1)
        {
            insertTable(namedir,table);
            /* code */
        }else{
            searchNested(table);
        }
        
        printTmpLL();
    }
    

    // do
    // {
    //     gets(nama);
    //     insertTable(nama);
    //     // system("cls");
    //     printData();
    //     /* code */
    // } while (1);
    printData();
    return 0;
}

