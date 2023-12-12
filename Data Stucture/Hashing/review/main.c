#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 5

struct data
{
    /* data */
    char value[30];
} * table[size];

//ANA
//(A*1 + N* 2 + A*3)%size
struct data * newData(char value[]){
    struct data * tmp = (struct data * )malloc(sizeof(struct data));
    strcpy(tmp->value,value);
    return tmp;
}

int hash(char key[]){
    int hashVal;
    int i,sum;
    sum = 0;
    for (i = 0; i < strlen(key); i++)
    {
        sum += key[i]*(i+1);
    }
    hashVal = sum % size;
    return hashVal;
}

void insert(char key[]){
    struct data * tmp = newData(key);
    int hashVal = hash(key);
    if (table[hashVal] == NULL)
    {
        table[hashVal] = tmp;
    }else{
        int iter = hashVal+1;
        while (iter != hashVal && table[iter]!=NULL)
        {
            iter = (iter+1)%size;
        }
        if(iter!=hashVal){
            table[iter] = tmp;
        }     
    }
}

void print(){
    for (int i = 0; i < size; i++)
    {
        printf("%s\n",table[i]->value);
    }
}


int main(){
    return 0;
}