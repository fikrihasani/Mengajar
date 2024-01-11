#include <stdio.h>

int counter = 0;
int fib(int n){
    counter+=1;
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else return (fib(n-1) + fib(n-2));
}
int main(){
    // int T;
    // scanf("%d");
    for(int i = 0 ; i < 10; i++){
        printf("number of fib called: %d - fib = %d - i: %d\n",counter, fib(i),i);
        counter = 0;
    }
    return 0;
}