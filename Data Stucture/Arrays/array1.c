#include <stdio.h>

//input 
//traverse -> akses dan print
//delete
#define MAX_N 100

void input(int bil[], int *idx){
    //bilangan a adalah bilangan yang akan diinput ke dalam array
    int bilInput;
    scanf("%d",&bilInput);
    bil[*idx] = bilInput;
    (*idx)++;
}

void print(int bil[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d\n",bil[i]);
    }
    
}

//hapus element pertama
void deleteFront(int bil[],int *size){
    for (int i = 0; i < *size; i++)
    {
        /* code */
        bil[i] = bil[i+1];
    }
    (*size)--;
}

void deleteBack(int *size){
    (*size)--;
}

//cari bilangan yang dihapus dari array
int deleteElement(int elToDel, int bil[], int *size){
    // algoritma hapus element
    for(int i = 0; i < *size; i++){
        if (bil[i] == elToDel)
        {
            /* code */
            for (int j = i; j < *size; j++)
            {
                /* code */
                bil[j] = bil[j+1];
            }
            (*size)--;
            return i;
        }
        
    }
    // jika elemen tidak ada
    return -1;
}

int main(){
    //data yang akan diproses
    int bil[MAX_N];

    // melakukan input data ke array bil
    int n;
    scanf("%d",&n);
    int i = 0;
    int idx = 0;
    while(i < n){
        input(bil,&i);
    }
    print(bil,i);
    printf("\n");
    // deleteFront(bil,&i);
    int eltoDel;
    printf("input bilangan yang ingin dihapus: ");
    scanf("%d",&eltoDel);
    deleteElement(eltoDel,bil,&i);
    print(bil,i);

}