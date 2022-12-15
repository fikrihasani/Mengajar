#include <stdio.h>
#include <stdlib.h>

// satu block node linked list
struct tnode {
    //menyimpan data
    int value;
    //menyimpan address setelahnya 
    struct tnode *next;
};

struct tnode *head = NULL;
struct tnode *tail = NULL;

// untuk inisiasi node baru;
struct tnode * initNode(int x){
    struct tnode *ptr = (struct tnode *)malloc(sizeof(struct tnode));
    ptr->value = x;
    ptr->next = NULL;
    return ptr;
}

// untuk print all element
void printList(){
    struct tnode *iter = head;
    while (iter)
    {
        /* code */
        printf("%d\n",iter->value);
        iter = iter->next;
    }
}

// insert front node
void insertFront(int x){
    //insert infront
    struct tnode *ptr = initNode(x);
    ptr->next = head;
    head = ptr;
}

// insert last node
void insertLast(int x){
    //insert in the last
    //buat node nya
    struct tnode *tmp = initNode(x);
    
    // struct tnode *varBaru = head;
    // while(varBaru->next){
    //     varBaru = varBaru->next;
    // }
    // varBaru->next = tmp;
    tail->next = tmp;
    tail = tmp;
}

void delete(int x){
    // misal head = NULL = false
    //mengecek apakah element head ada?
    //head->next == NULL 
    if(head && head->value == x && !head->next){
        //elemen satu satunya yang ada di linked list
        free(head);
    }else if(head->value == x){
        //delete element di paling depan
        struct tnode *iterDel = head;
        head = head->next;
        iterDel->next = NULL;
        free(iterDel);
    }else{
        struct tnode *iter = head;
        while(iter->next && iter->next->value != x){
            iter = iter->next;
        }
        printf("element ada: %d\n",iter->value);
        struct tnode *iterDel = iter->next;
        iter->next = iter->next->next;
        free(iterDel);
    }
}

// insert element so linked list is sorted ascending
void insertSorted(int x){
    if(x < head->value){
        insertFront(x);
    }else if(x > tail->value ){
        insertLast(x);
    }else{
        struct tnode *iter = head;
        while(iter->next->value < x){
            iter = iter->next;
        }
        printf("data iter: %d\n",iter->value);
        struct tnode *node = initNode(x);
        node->next = iter->next;
        iter->next = node;
    }

}
int main(){
    //isi data. inisiasi data linked list
    tail = head = initNode(4);

    // printf("%d - %d",head,tail);
    //insert infront
    insertSorted(3);
    insertSorted(7);
    printList();

    insertSorted(20);

    //print data yang ada di linked list
    printList();
    printf("tail value: %d",tail->value);
    // //insert last
    // insertLast(17);
    // //print data yang ada di linked list
    // printList();

    // // delete node
    // // delete jika elemen hanya ada 1
    // int x = 17;
    // //delete element
    // delete(17);
    // // print element
    // printList();
    return 0;
}