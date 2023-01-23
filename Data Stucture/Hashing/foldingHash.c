#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 26
int main(){
    int value;
    int key;
    long long int hashed;
    char buffer[50];
    value = 5628;
    sprintf(buffer,"%d",value);
    int sum = 0;
    // algoritma folding - cr.Dexter
    int iter = 0;
    int tmp = 0;
    while (iter<strlen(buffer))
    {
        /* code */
        if(iter % 2 == 0 && iter+1<strlen(buffer)){
            tmp += (buffer[iter] - '0')*10;
        }else{
            tmp += (buffer[iter] - '0');
        }
        iter++;
    }
    tmp = tmp%SIZE;
    printf("%d\n",tmp);

    // division
    return 0;
}