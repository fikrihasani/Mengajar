#include <stdio.h>
#define MAXSIZE 100

//insert pada posisi size
// kemudian size + 1
void insert(int arr[],int x, int * size){
    arr[*size] = x;
    *size += 1;
}

//delete elemen depan
//size -1
void delete(int arr[],int *size){
    //gimana deletenya
    //kita geser dari 1 sampai size kedepan
    for(int i = 1; i<*size;i++){
        arr[i-1] = arr[i];
    }
    *size -= 1;
}

void display(int arr[],int size){
    for(int i = 0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[MAXSIZE];
    int x;
    int size = 0;
    //input selama bilangan positif
    scanf("%d",&x);
    while(x > 0){
        //pass param by reference
        insert(arr,x,&size);
        scanf("%d",&x);
    }
    display(arr,size);
    delete(arr,&size);
    printf("%d\n",size);
    display(arr,size);

}