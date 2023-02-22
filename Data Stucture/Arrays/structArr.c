#include <stdio.h>
#include <string.h>

char vok[] = "aiueo";
struct data
{
    /* data */
    char s[30];
    int vok;
};

int countVok(char s[]){
    int totalVok = 0;
    for(int i = 0; i<strlen(s); i++){
        if(strchr(vok,s[i])){
            totalVok+=1;
        }
    }
    return totalVok;
}

int main(){
    struct data arrData[5];
    for(int i = 0; i<5;i++){
        scanf("%s",arrData[i].s);
        arrData[i].vok = countVok(arrData[i].s);
    }
    for(int i = 0; i<5;i++){
        printf("%s - %d\n",arrData[i].s,arrData[i].vok);
    }
    for(int i = 0; i<4; i++){
        for(int j = i+1; j<5; j++){
            if(arrData[j].vok<arrData[i].vok){
                struct data tmp;
                tmp = arrData[j];
                arrData[j] = arrData[i];
                arrData[i] = tmp;
            }else if(arrData[j].vok == arrData[i].vok){
                if(strcmp(arrData[j].s,arrData[i].s) < 0){
                    struct data tmp;
                    tmp = arrData[j];
                    arrData[j] = arrData[i];
                    arrData[i] = tmp;
                }
            }
        }
    }
    for(int i = 0; i<5;i++){
        printf("%s\n",arrData[i].s);
    }
    //sort by vok
    //sort by alphabet
    
    return 0;
}