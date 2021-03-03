#include <stdio.h>
#include <stdlib.h>

struct Node
{
    /* data */
    int data;
    // pointer ke node yang lain
    struct Node *next;
};




int main(){
    // head;
    struct Node *ll = NULL; 
    ll = (struct Node *) malloc(sizeof(struct Node));
    ll->data = 5;
    ll->next = NULL;
    printf("%d ",ll->data);

    // insert node setelah head
    // inisialisasi node
    // pointer ll->next menunjuk ke node baru
    return 0;
}