#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item
{
    /* data */
    char name[20];
    int stock;
    float price;
    
}items[100];

int getTotalData = 0;
struct item items[100];

void insert(struct item It){

    strcpy(items[getTotalData].name,It.name);
    items[getTotalData].stock = It.stock;
    items[getTotalData].price = It.price;
    getTotalData++;
}

int main(){
    system("cls");

    struct item It;

    // insert data
        strcpy(It.name,"nama");
        It.stock = 5;
        It.price = 5000;
        insert(It);

    for (int i = 0; i < getTotalData; i++)
    {
        /* code */
        printf("%s\t%d\t%.3f\n",It.name,It.stock, It.price);
    }
    
    return 0;
}
