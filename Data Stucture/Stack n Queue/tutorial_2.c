//linked list implementation
#include <stdio.h>
#include <stdlib.h>

struct node
{
    /* data */
    int val;
    // menyimpan next pointer
    struct node * next;
};

//struct queue untuk menyimpan front dan rear node
struct q{
    struct node * front, * rear;
};

struct node * qnode = NULL;
struct q * queue = NULL;

//inisiasi queue
struct q * createQ(){
    struct q * tmp = (struct q *)malloc(sizeof(struct q));
    //init front dan rear pointer
    tmp->front = tmp->rear = NULL;
    return tmp;
}

// inisiasi qnode
struct node * createNode(int val){
    struct node * tmp = (struct node *)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;
    return tmp;
}

// push atau enque (isi data)
void enque(int val){
    // membuat node baru
    struct node * tmp  = createNode(val);
    // cek kosong
    if(queue->front == NULL && queue->rear == NULL){
        queue->front = queue->rear = tmp;
    }else{
        queue->rear->next = tmp;
        queue->rear = tmp;
    }
}

//void untuk print isi dari q
void printQ(){
    struct node * iter = queue->front;
    while (iter)
    {
        /* code */
        printf("%d ",iter->val);
        iter = iter->next;
    }
    printf("\n");
}

//pop element depan
void deque(){
    // dicek queuenya kosong atau tidak(stephanie)
    if(queue->front == NULL && queue->rear == NULL){
        return;
    }
    //case 2 ada elementnnya
    struct node * tmp = queue->front;
    queue->front = queue->front->next;

    //case 3: queue ada isinya, tapi sisa 1 node
    if(queue->front == NULL){
        queue->rear = NULL;
    }

    //free memory untuk front
    free(tmp);
}

int main(){
    //inisiasi queue dan segala isinya
    queue = createQ();
    enque(5);
    enque(8);
    printQ();
    deque();
    printQ();
    deque();
    printQ();
    return 0;
}
