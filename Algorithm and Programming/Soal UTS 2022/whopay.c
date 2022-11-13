#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int paybook[n*2];
    int sumAan, sumKenken;
    sumAan = sumKenken = 0;
    for(int i=0; i<n*2; i++){
        scanf("%d",&paybook[i]);
    }
    int iter;
    if(n % 2 ==0){
        iter = 1;
        while (iter<=n){
            paybook[iter] += 2000;
            iter += 2;
        }

    }else{
        iter = 0;
        while (iter<=n){
            paybook[iter] += 2000;
            iter += 2;
        }
    }
    for(int i = 0; i<n;i++){
        sumAan += paybook[i];
        sumKenken += paybook[n+i];
    }
    if(sumAan > sumKenken){
        printf("aan\n");
    }else{
        printf("kenken\n");
    }
    return 0;
}
