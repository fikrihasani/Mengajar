#include <stdio.h>

int main(){
    FILE *fp;
    struct animeRating{
        char anime[100];
        int rating;
    } animeData[5];

    fp = fopen("lb01_4.txt","r");
    if(fp == NULL){
        return -1;
    }
    int i = 0;
    while(fscanf(fp,"%[^,],%d",animeData[i].anime,&animeData[i].rating) != EOF){
        i++;
    }
    printf("%s, rating: %d\n",animeData[0].anime,animeData[0].rating);

    for(int i = 0; i<5;i++){
        printf("%s - %d\n",animeData[i].anime,animeData[i].rating);
    }

    return 0;
}