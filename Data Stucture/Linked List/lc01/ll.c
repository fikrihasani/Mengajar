#include <stdio.h>
#include <stdlib.h>

//data struct
struct node {
    int val;
    struct node * next;
};

struct node *head = NULL;

//fungsi init node
struct node * initNode(int val){
    struct node * tmp = (struct node *)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;
    return tmp;
}
//print elements
void printLL(){
    //ada sebuah variable, inisiasi untuk iterasi
    struct node * curr = head;
    while (curr != NULL)
    {
        /* code */
        printf("%d ",curr->val);
        //perpindahan node
        curr = curr->next;
    }
    printf("\n");
}

//search function
//accept int as parameter
//return node if found
//return null if not found (this will be automatically null ya karena saat ga ketemu akhir iterasi akan null)
struct node * search(int searchVal){
    //cek apakah linked listnya sudah ada
    if(head == NULL){
        return NULL;
    }else{
        struct node * curr = head;
        while(curr != NULL && curr->val != searchVal){
            curr = curr->next;
        }
        return curr;
    }
}

//insert head
void insertHead(int val){
    struct node * tmp = initNode(val);
    tmp->next = head;
    head = tmp;
}

//insert new node after last element of linked list
void insertLast(int val){
    //how?
    struct node * curr = head;
    //hint : get last node first
    while(curr->next){
        curr = curr->next;
    }
    struct node * tmp = initNode(val);
    curr->next = tmp;
    //after that connect new node created from initNode to the last node using next
}

//delete
void delete(int val){
    struct node * curr = head;
    if(head->val == val){
        head = head-> next;
        free(curr);
    }else{
        while(curr->next && curr->next->val != val){
            curr = curr->next;
        }
        //cek
        if (curr->next)
        {
            /* code */
            struct node * del = curr->next;
            curr->next = del->next;
            free(del);
        }
    }
}
//main func
int main(){
    //alokasi address memory untuk sebuah node
    head = initNode(10);
    //insert depan
    insertHead(20);
    insertHead(30);
    //akses member pake panah karena struct pointer
    printLL();
    struct node * s = search(15);
    if(s){
        printf("data ada\n");
    }else{
        printf("data tidak ada\n");
    }
    delete(15);
    printLL();
    insertLast(2);
    printLL();
    return 0;
}