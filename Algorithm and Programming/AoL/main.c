#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct data
{
    /* data */
    char loc1[26];
    char loc2[26];
    int price;
    int rooms;
    int bathrooms;
    int carParks;
    char type[26];
    int area;
    char furnish[26];

} arrData[4000];
int counter;
FILE * fp;

int initFile(){
    fp = fopen("file.csv","r");
    if(fp == NULL){
        return 0;
    }
    return 1;
}

int strCmpSub(char s1[], char s2[]){
    int isPresent = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        isPresent = 0;
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i + j] != s2[j]) {
                isPresent = 0;
                break;
            }
            isPresent = 1;
        }
        if (isPresent) {
            break;
        }
    }
     
    if (isPresent) {
        return 1;
    } else {
        return 0;
    }
}

void menu(int *inp){
    int tmp;
    printf("AoL Case Study\n");
    printf("1. Describe\n");
    printf("2. Sort Data\n");
    printf("3. Search Data\n");
    printf("4. Print Data\n");
    printf("0. Exit\n");
    printf("What is your choice? ");
    scanf("%d",&tmp);
    *inp = tmp;
}

void readData(){
    counter = 0;
    char ss[100];
    // fgets(ss,100, fp);
    while (!feof(fp))
        {
            int tmp = fscanf(fp,"%[^;];%[^;];%d;%d;%d;%d;%[^;];%d;%s\n",arrData[counter].loc1,arrData[counter].loc2,&arrData[counter].price, &arrData[counter].rooms, &arrData[counter].bathrooms, &arrData[counter].carParks, arrData[counter].type, &arrData[counter].area, arrData[counter].furnish); 
            counter++;
        }
    fclose(fp);
    printf("Data has been loaded\n");
}

void printData(){
    int maxLoop;
    printf("Input number of data to be displayed. (input -1 to display all data): ");
    scanf("%d",&maxLoop);
    if (maxLoop == -1){
        maxLoop = counter;
    }
    // int i = 5;
    // printf("%s,%s,%d,%d,%d,%d,%s,%d,%s",arrData[i].loc1,arrData[i].loc2,arrData[i].price, arrData[i].rooms, arrData[i].bathrooms, arrData[i].carParks, arrData[i].type, arrData[i].area, arrData[i].furnishing); 

    for(int i = 0; i<maxLoop; i++){
        if(i == 0){
            printf("%-16s | %-20s | %-2d | %-2d | %-2d | %-2d | %-2s | %-2d | %-2s\n",arrData[i].loc1,arrData[i].loc2,arrData[i].price, arrData[i].rooms, arrData[i].bathrooms, arrData[i].carParks, arrData[i].type, arrData[i].area, arrData[i].furnish); 

        }else{
            printf("%-17s | %-20s | %-7d | %-2d | %-2d | %-2d | %-2s | %-2d | %-2s\n",arrData[i].loc1,arrData[i].loc2,arrData[i].price, arrData[i].rooms, arrData[i].bathrooms, arrData[i].carParks, arrData[i].type, arrData[i].area, arrData[i].furnish); 

        }
    }
    printf("\n");
}

void sortString(){

}

void sortNum(){
    
}

int check(char s[],char val[4000][26]){
    int exist = 0;
    for(int i=0; i<4000 && strcmp(val[i],"")!=0; i++){
        if(strcmp(val[i],s) == 0){
            exist = 1;
            return exist;
        }
    }
    return exist;
}
void countFreq(char val[4000][26], int count[4000]){
    for(int i = 0; i<4000 && strcmp(val[i],"")!=0;i++){
        for(int j = 0; j<4000;j++){
            if(strcmp(val[i],arrData[j].loc1) == 0){
                count[i] += 1;
            }
        }
    }
}

int getMaxFreq(int count[],int idx){
    int pos = 0;
    for(int i = 0; i<idx && count[i]!=0;i++){
        if(count[i] >= count[pos]){
            pos = i;
        }
    }
    return pos;

}

int getMinFreq(int count[],int idx){
    int pos = 0;
    for(int i = 1; i<idx && count[i]!=0;i++){
        if(count[i] <= count[pos]){
            pos = i;
        }
    }
    return pos;
}
void describe(){
    char colName[26];
    printf("Input col name to describe: ");
    scanf("%s",colName);
    char val[4000][26];
    int count[4000];
    for(int i = 0; i<4000;i++){
        strcpy(val[i],"");
        count[i] = 0;
    }
    int idx = 0;
    if(strcmp(colName,"loc1")==0){
        for(int i = 0; i<4000;i++){
            int exist = 0;
            exist = check(arrData[i].loc1,val);
            if(!exist){
                strcpy(val[idx],arrData[i].loc1);
                idx++;
            }
        }
    }
    printf("%d\n",idx);

    countFreq(val,count);
    for(int i = 0; i<idx;i++){
        printf("%d",count[i]);
    }
    for(int i = 0; strcmp(val[i],"")!=0 && i<4000; i++){
        printf("%s : %d\n",val[i],count[i]);
    }
    int idxMax = getMaxFreq(count,idx);
    int idxMin = getMinFreq(count,idx);
    printf("Maximum value: %s with frequency: %d\n",val[idxMax],count[idxMax]);
    printf("Minimum value: %s with frequency: %d\n",val[idxMin],count[idxMin]);
}
void sort(char comment[], int colPos){
    printf("input your prompt: ");
    char contr[10];
    char col[26];
    scanf("%s %s",contr,col);
    if(colPos == 0 || colPos == 1 || colPos == 7 || colPos == 9){
        sortString();
    }else{
        sortNum();
    }
}

void trimFirst(char s[]){
    char tmp[26] = "";
    for(int i = 1; i<strlen(s);i++){
        strncat(tmp,&s[i],1);
    }
    strcpy(s,tmp);
}

void trimLast(char s[]){
    char tmp[26] = "";
    for(int i = 0; i<strlen(s)-1;i++){
        strncat(tmp,&s[i],1);
    }
    strcpy(s,tmp);
}

int getVal(char ss[], int idx, char val[10][100], int *valIdx){
    // printf("this function is called\n");
    char s[100] = "";
    if(idx != 0){
        idx = idx+3;
    }
    int j = 0;
    for(j = idx; j<strlen(ss) && (ss[j]!='i' || ss[j+1]!='n' || ss[j+2]!=' '); j++){
        strncat(s,&ss[j],1);
    }
    trimLast(s);
    strcpy(val[*valIdx],s);
    *valIdx += 1;
    return j;
}
void getCol(char ss[], int idx, char col[10][100], int *colIdx){
    // printf("this function is called\n");
    char s[100] = "";
    for(int j = idx; j<strlen(ss) && (ss[j]!='a' || ss[j+1]!='n' || ss[j+2]!='d'); j++){
            strncat(s,&ss[j],1);
    }
    trimFirst(s);
    strcpy(col[*colIdx],s);
    *colIdx += 1;
}



void find(char val[10][100], char col[10][100],int idxVal, int idxPos[]){
    int exist = 1;
    int tmpFind;
    int idx = 0;
    for(int i=0;i<idxVal; i++){
        char tmpV[100];
        char tmpCol[100];
        strcpy(tmpV,val[i]);
        strcpy(tmpCol,col[i]);
        char tmp[100] = "";
        tmpFind = 0;
        if(strcmp("loc1",tmpCol) == 0){
            for(int j = 0; j<4000; j++){
                if(strCmpSub(arrData[j].loc1,tmpV)){
                    tmpFind = 1;
                    idxPos[idx] = j;
                    idx++;
                }
                strcpy(tmp,"");

            }
            exist *= tmpFind;
        }
        if(strcmp("loc2",tmpCol) == 0){
            printf("loc2 goes\n");
            for(int j = 0; j<4000; j++){
                if(strCmpSub(arrData[j].loc2,tmpV)){
                    tmpFind = 1;
                    idxPos[idx] = j;
                    idx++;

                }
                strcpy(tmp,"");

            }
            exist *= tmpFind;
        }
        if(strcmp("type",tmpCol) == 0){
            printf("type goes\n");
            for(int j = 0; j<4000; j++){
                if(strCmpSub(arrData[j].type,tmpV)){
                    tmpFind = 1;
                    idxPos[idx] = j;
                    idx++;
                }
                strcpy(tmp,"");
            }
            exist *= tmpFind;
        }

        if(strcmp("furnish",tmpCol) == 0){
            printf("furnish goes\n");
            for(int j = 0; j<4000; j++){
                if(strCmpSub(arrData[j].furnish,tmpV)){
                    tmpFind = 1;
                    idxPos[idx] = j;
                    idx++;
                }
                strcpy(tmp,"");
            }
            exist *= tmpFind;
        }
    }
}
void search(){
    char ss[200];
    printf("Input your Command for search: \n");
    getchar();
    scanf("%[^\n]",ss);
    int aPos[100];
    char val[10][100];
    char col[10][100];
    for (int i = 0; i < 100; i++)
    {
        /* code */
        aPos[i] = 0;
    }
    
    int countA = 0;
    for(int i = 0; i < strlen(ss); i++){
        if(ss[i] =='a' && ss[i+1] =='n' && ss[i+2] == 'd'){
            aPos[countA] = i;
            countA++;
        }
    }
    // printf("%d\n",countA);
    int valIdx = 0;
    int colIdx = 0;
    int idx = 0;
    int j = getVal(ss,idx,val,&valIdx);
    getCol(ss,j+2,col,&colIdx);
    for(int i = 0; i<100 && aPos[i] != 0; i++){
        // printf("%d\n",aPos[i]);
        idx = aPos[i];
        j = getVal(ss,idx,val,&valIdx);
        getCol(ss,j+2,col,&colIdx);
    }
    for(int i=0;i<valIdx;i++){
        printf("%s-%s\n",val[i],col[i]);
    }
    int idxPos[4000];
    for (int i = 0; i < 4000; i++)
    {
        /* code */  
        idxPos[i] = -1;
    }
    
    find(val,col,valIdx,idxPos);
    printf("%d",idxPos[1]);
    for(int i = 0; idxPos[i]!=-1;i++){
        printf("%-17s | %-20s | %-7d | %-2d | %-2d | %-2d | %-2s | %-2d | %-2s\n",arrData[idxPos[i]].loc1,arrData[idxPos[i]].loc2,arrData[idxPos[i]].price, arrData[idxPos[i]].rooms, arrData[idxPos[i]].bathrooms, arrData[idxPos[i]].carParks, arrData[idxPos[i]].type, arrData[idxPos[i]].area, arrData[idxPos[i]].furnish); 
    }
}
int main(){
    if(initFile()){
        initFile();
        readData();
        int inp;
        inp = 0;
        menu(&inp);
        printf("%d\n",inp);
        // system("cls");
        while (inp!=0)
        {
            /* code */

            switch (inp)
            {
                case 1:
                    // sort();
                    describe();
                    break;
                case 2:
                    break;
                case 3:
                    search();
                    break;
                case 4:
                    printData(100);
                    break;
                default:
                    break;
            }
            
            // system("cls");
            menu(&inp);
            printf("%d\n",inp);
        }
        
        // printData(-1);
    }else{
        printf("File Not Found\n");
        return 0;
    }
}