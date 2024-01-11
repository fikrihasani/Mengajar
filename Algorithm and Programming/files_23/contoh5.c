#include <stdio.h>

int main(){
    FILE * fp;
    char name[20] = "tono";
    int score = 50;

    fp = fopen("data3.csv","a");
    fprintf(fp,"%s,%d\n",name,score);
    return 0;

}