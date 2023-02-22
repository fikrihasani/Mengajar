#include <stdio.h>
#include <stdlib.h>

struct node
{
    /* data */
    int val;
    struct node * next;
    struct node * prev;
};

struct node * dll1head = NULL;
struct node * dll1tail = NULL;

struct node * dll2head = NULL;
struct node * dll2tail = NULL;

struct node * initNode(int val){
    struct node * tmp = (struct node *)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = tmp->prev = NULL;
    return tmp;
}

void insertHeadDl1(int val){
    struct node * tmp = initNode(val);
    tmp->next = dll1head;
    dll1head->prev = tmp;
    dll1head = tmp;
}

void insertLastDl1(int val){
    struct node * tmp = initNode(val);
    dll1tail->next = tmp;
    tmp->prev = dll1tail;
    dll1tail = tmp;
}
//buat fungsi sama lagi untuk Dll2. disini kita blm ngomong double pointer ya biar ga pusing
void insertHeadDl2(int val){
    struct node * tmp = initNode(val);
    tmp->next = dll2head;
    dll2head->prev = tmp;
    dll2head = tmp;
}

void insertLastDl2(int val){
    struct node * tmp = initNode(val);
    dll2tail->next = tmp;
    tmp->prev = dll2tail;
    dll2tail = tmp;
}

//bikin fungsi untuk melakukan insertLastDl2 saat iterasi dari tail nya Dl1 ke head

void printHead(struct node * head){
    struct node * curr = head;
    while (curr)
    {
        printf("%d ",curr->val);
        curr = curr->next;
    }
    printf("\n");
}

void printTail(struct node * tail){
    struct node * curr = tail;
    while (curr)
    {
        printf("%d ",curr->val);
        curr = curr->prev;
    }
    printf("\n");
}

void inverse(){
    struct node * curr = dll1tail;
    dll2head = dll2tail = curr;
    curr = curr->prev;
    while (curr)
    {
        insertLastDl2(curr->val);
        curr = curr->prev;
    }
}

int main(){
    //init sebuah node, untuk linked list kosong
    //head = tail
    //dll1
    dll1head = dll1tail = initNode(5);
    insertHeadDl1(10);
    insertLastDl1(7);
    printHead(dll1head);

    inverse();

    printHead(dll2head);
    return 0;
}