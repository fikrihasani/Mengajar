#include <stdio.h>

int main(){
    FILE *fp;
    int score;
    int max = 0;
    int T;
    fp = fopen("case2.txt", "r");

    if(fp==NULL){
        printf("data not found.\n");
    }else{
        while(!feof(fp)){
            fscanf(fp,"%d\n", &T);
            max = 0;
            for(int i = 0; i<T;i++){
                fscanf(fp, "%d", &score);

                if(max<score){
                    max = score;
                }
            }
            printf("%d\n", max);
        }
    }
    return 0;
}