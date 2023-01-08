#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct data
{
    /* data */
    char loc1[26];
    char loc2[26];
    float price;
    int rooms;
    int bathrooms;
    int carParks;
    char type[26];
    float area;
    char furnishing[26];

} arrData[4000];
int counter;
FILE * fp;

int initFile(){
    fp = fopen("file.txt","r");
    if(fp == NULL){
        return 0;
    }
    return 1;
}

void readData(){
    counter = 0;
    char ss[100];
    // fgets(ss,100, fp);
    while(!feof(fp)){
        fgets(ss,100,fp);
        counter++;
        printf("%d\n",counter);
    }
    fclose(fp);
    // while(fscanf(fp,"%[^,],%[^,],%f,%d,%d,%d,%[^,],%f,%[^\n]",arrData[counter].loc1,arrData[counter].loc2,&arrData[counter].price, &arrData[counter].rooms, &arrData[counter].bathrooms, &arrData[counter].carParks, arrData[counter].type, &arrData[counter].area, arrData[counter].furnishing) != EOF){
    //     counter++;
    //     printf("%c - %s - %d - %d - %d",arrData[counter].loc1, arrData[counter].loc2, arrData[counter].bathrooms, arrData[counter].rooms, arrData[counter].carParks);
    //     printf("%d\n",counter);
    // }
    printf("Data has been loaded\n");
}

void printData(){
	int i;
    for(i = 0; i<counter; i++){
        printf("%s - %s - %d - %d - %d",arrData[i].loc1, arrData[i].loc2, arrData[i].bathrooms, arrData[i].rooms, arrData[i].carParks);
    }
}

int main(){
    if(initFile()){
        // readData();
        // printData();
        char ss[100];
        counter = 0;
        int tmp;
        tmp = fscanf(fp,"%[^,],%[^,],%f,%d,%d,%d,%[^,],%f,%[^\n]",arrData[counter].loc1,arrData[counter].loc2,&arrData[counter].price, &arrData[counter].rooms, &arrData[counter].bathrooms, &arrData[counter].carParks, arrData[counter].type, &arrData[counter].area, arrData[counter].furnishing); 
        counter++;
        printData();

        printf("%d",tmp);
        fscanf(fp,"%[^,],%[^,],%f,%d,%d,%d,%[^,],%f,%[^\n]",arrData[counter].loc1,arrData[counter].loc2,&arrData[counter].price, &arrData[counter].rooms, &arrData[counter].bathrooms, &arrData[counter].carParks, arrData[counter].type, &arrData[counter].area, arrData[counter].furnishing); 
        counter++;

        printData();
        while (counter != 100)
        {
            /* code */
            // fgets(ss,100, fp);
            // printf("%s",ss);
            fscanf(fp,"%[^,],%[^,],%f,%d,%d,%d,%[^,],%f,%[^\n]",arrData[counter].loc1,arrData[counter].loc2,&arrData[counter].price, &arrData[counter].rooms, &arrData[counter].bathrooms, &arrData[counter].carParks, arrData[counter].type, &arrData[counter].area, arrData[counter].furnishing); 
            counter++;
        }
        printData();

    }else{
        printf("File Not Found\n");
        return 0;
    }
}
