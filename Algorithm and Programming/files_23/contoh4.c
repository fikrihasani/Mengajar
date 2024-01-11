#include <stdio.h>

int main(){
    FILE * fp;
    char name[20];
    int score;
    //buka file
    fp = fopen("datas.csv","r");
    if (!fp)
    {
        /* code */
        printf("cannot open file");
    }else{
        while (fscanf(fp,"%[^,],%d\n",name,&score) != EOF)
        {
            /* code */
            printf("name: %s - score: %d\n",name,score);
        }

    }
    
    return 0;
}