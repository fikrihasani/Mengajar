//linked list implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    /* data */
    int prio;
    char name[30];
    char cond[15];
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

int convertCond(char cond[]){
    if(strcmp(cond,"CRITICAL")==0){
        return 4;
    }else if(strcmp(cond,"SERIOUS") == 0){
        return 3;
    }else if(strcmp(cond,"FAIR") == 0){
        return 2;
    }else{
        return 1;
    }

}
// inisiasi qnode
struct node * createNode(char name[], char cond[]){
    struct node * tmp = (struct node *)malloc(sizeof(struct node));
    tmp->prio = convertCond(cond);
    strcpy(tmp->name,name);
    strcpy(tmp->cond,cond);
    tmp->next = NULL;
    return tmp;
}

// push atau enque (isi data)
void enque(char name[],char cond[]){
    // membuat node baru
    struct node * tmp  = createNode(name,cond);
    // cek kosong
    if(queue->front == NULL && queue->rear == NULL){
        queue->front = queue->rear = tmp;
    }else{
        //case 1, when val is > front->val
        if(tmp->prio > queue->front->prio){
            tmp->next = queue->front;
            queue->front = tmp;
        }else if(tmp->prio <= queue->rear->prio){
            // case 2, when val < rear->val
            queue->rear->next = tmp;
            queue->rear = tmp;
        }else{
            // case 3 diluar semua
            struct node * iter = queue->front;
            while (iter->next->prio >= tmp->prio)
            {
                /* code */
                printf("%d\n",iter->prio);
                iter = iter->next;
            }
            tmp->next = iter->next;
            iter->next = tmp;
        }
    }
}

//void untuk print isi dari q
void printQ(){
    struct node * iter = queue->front;
    while (iter)
    {
        /* code */
        printf("%s ",iter->name);
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
    int N;
    scanf("%d",&N);
    char c1[10], c2[30],c3[10];
    queue = createQ();
    while (N > 0)
    {
        /* code */
        //command
        scanf("%s",c1);
        if(strcmp(c1,"ADD") == 0){
            scanf("%s",c2);
            scanf("%s",c3);
            printf("%s - %s - %s\n",c1,c2,c3);
            enque(c2,c3);
            printQ();
        }else if(strcmp(c1,"CALL") == 0){
            if(strcmp(queue->front->cond,"CRITICAL") == 0){
                printf("%s is in the Emergency Room\n",queue->front->name);
            }else if(strcmp(queue->front->cond,"SERIOUS") == 0){
                printf("%s is in the Examination Room\n",queue->front->name);
            }else{
                printf("%s is in the Consultation Room\n",queue->front->name);
            }
            deque();
            printQ();
        }
        N--;
    }

    
    // enque(5);
    // enque(8);
    // printQ();
    // enque(7);
    // enque(4);
    // enque(5);
    // printQ();
    return 0;
}
