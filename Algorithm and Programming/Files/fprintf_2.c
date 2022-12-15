#include <stdio.h>
#include <string.h>

// fputs untuk write string datas to file

int main(){
    FILE *fp;
    int inp = 1;
    char ss[5][100];
    int rating[5];
    strcpy(ss[0],"bluelock");
    strcpy(ss[1],"SpongeBob");
    strcpy(ss[2],"Chainsaw Man");
    strcpy(ss[3],"Gundam Witch from mercury");
    strcpy(ss[4],"Spy X Family");

    rating[0] = 87;
    rating[1] = 90;
    rating[2] = 90;
    rating[3] = 85;
    rating[4] = 97;
    fp = fopen("lb01_4.txt","w");
    if(fp == NULL){
        return -1;
    }

    for(int i = 0; i<5; i++){
        fprintf(fp,"%s,%d\n",ss[i],rating[i]);
    }

    fclose(fp);
    return 0;
}