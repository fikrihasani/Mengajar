#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
};

struct node * head = NULL;
struct node * tail = NULL;

struct node * init(int val){
    struct node * tmp = (struct node *)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;
}

void print(){
    struct node * curr = head;
    while (curr)
    {
        /* code */
        printf("%d ",curr->val);
        curr = curr->next;
    }
    printf("\n");
}
void insert(int val){
    //jika linked list kosong
    if(!head && !tail){
        head = tail = init(val);
    }else
    {
        struct node * tmp = init(val);
        // case 1, val < head->val, pendekatan insertHead()
        if(val < head->val){
            tmp->next = head;
            head = tmp;
        }else if(val > tail->val){
            //case 2 , val > tail->val, pendekatan insertTail()
            tail->next = tmp;
            tail = tmp;
        }else{
            //kalau bukan keduanya, lakukan loop dari head, sampai kondisi
            struct node * curr = head;
            //while val ngapain ni?
            while(curr->next && val > curr->next->val){
                curr = curr->next;
            }
            tmp->next = curr->next;
            curr->next = tmp;
            //tempel tempel si tmp dan curr dan apa ?
        }
    }
}
int main(){
    int a;
    scanf("%d",&a);
    while(a > 0){
        insert(a);
        print();
        scanf("%d",&a);
    }
    return 0;
}