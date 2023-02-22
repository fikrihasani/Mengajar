#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    //save priority value
    int prio;
    char name[30];

    struct node *next;
};

//queue
struct q{
    struct node * front, *rear;
};

struct q * queue = NULL;
struct node * qnode = NULL; 

//init q
struct q * createQ(){
    struct q * tmp = (struct q*) malloc(sizeof(struct q));
    tmp->front = tmp->rear = NULL;
    return tmp;
}

//convert cond
int convertCond(char cond[]){
    if(strcmp(cond,"CRITICAL") == 0){
        return 4;
    }else if (strcmp(cond,"SERIOUS") == 0){
        return 3;
    }else if (strcmp(cond,"FAIR") == 0){
        return 2;
    }else{
        return 1;
    }
}

//inisasi node nya 
struct node * createNode(char name[], char cond[]){
    struct node * tmp = (struct node *)malloc(sizeof(struct node));
    tmp->prio = convertCond(cond);
    strcpy(tmp->name,name);
    tmp->next = NULL;
    return tmp;
}

//insert kedalam queue
void enque(char name[], char cond[]){
    //buat node baru tmp
    struct node * tmp = createNode(name,cond);
    //cek apakah queue kosong
    if(queue->front == NULL && queue->rear == NULL){
        queue->front = queue->rear = tmp;
    }else{
        //
        if(tmp->prio > queue->front->prio){
            tmp->next = queue->front;
            queue->front = tmp;
        }else if(tmp->prio <= queue->rear->prio){
            queue->rear->next = tmp;
            queue->rear = tmp;
        }else{
            struct node *iter = queue->front;
            while (iter->next->prio >= tmp->prio)
            {
                /* code */
                iter = iter->next;
            }
            tmp->next = iter->next;
            iter->next = tmp;
            
        }
    }
}

void deque(){
    if(queue->front && queue->rear){
        struct node * del = queue->front;
        if(del->prio == 4){
            printf("%s is in Emergency Room\n",del->name);
        }else if(del->prio == 3){
            printf("%s is in examination room\n",del->name);
        }else{
            printf("%s is in consultation room\n",del->name);
        }
        queue->front = queue->front->next;
        free(del);
    }

}
void printQ(){
    struct node * iter = queue->front;
    while(iter){
        printf("%s ",iter->name);
        iter = iter->next;
    }
    printf("\n");
}
int main(){
    int n;
    char c1[10],c2[30],c3[10];
    queue = createQ();
    scanf("%d",&n);
    while(n > 0){
        scanf("%s",c1);
        if(strcmp(c1,"ADD") == 0){
            scanf("%s %s",c2,c3);
            enque(c2,c3);
        }else{
            deque();

        }
        n--;
    }
    printf("Waiting room: "); printQ();
    return 0;
}
