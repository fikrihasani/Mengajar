#include <stdio.h>
#define MAX 100

int queue[MAX];

int rearIdx = -1;

// push data
void enque(int val){   
    //cek apakah queue sudah penuh
    if(rearIdx != MAX-1){
        rearIdx++;
        queue[rearIdx] = val;
    } 
}

//pop data
int deque(){
    int val = queue[0];
    //pergeseran elemen ke depan
    for(int i = 0; i<rearIdx; i++){
        queue[i] = queue[i+1];
    }
    rearIdx--;
    return val;
}

void printQ(){
    for(int i = 0; i<=rearIdx;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    enque(8);
    enque(9);
    enque(10);
    printQ();
    int head = deque();
    printQ();
}