#include<stdio.h>

int main(){
    FILE *fp;
    int n;
    float total = 0;
    int counter = 0;
    fp = fopen("dataCase1.txt","r");
    if(!fp){
        printf("File can't be opened");
        return 0;
    }else{
        char buffer[100];
        fscanf(fp,"%s\n",buffer);
        while(!feof(fp)){
            fscanf(fp, "%d\n", &n);
            total+=n;
            counter++;
        }
    }
    printf("Rata-rata: %.2f\n", total/counter);
    printf("Total: %f\n", total);

    return 0;
}
