#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 5

char data[size][12];

// merubah karakter pertama menjadi index (lowercase)
int hashing(char c){
    return (c-'a')%size; 
}

void initTable(){
    for (int i = 0; i < size; i++)
    {
        /* code */
        strcpy(data[i],"");
    }
}

int search(char key[]){
    int hashVal = hashing(key[0]);
    if (strcmp(data[hashVal],key) == 0)
    {
        /* code */
        return hashVal;
    }else
    {
        /* code */
        int i = hashVal+1;
        while (i!=hashVal)
        {
            /* code */
            if (strcmp(data[i],key) == 0)
            {
        /* code */
                return hashVal;
                break;
            }
            i = (i+1)%size;
        }
    }
    return -1;
    
}

void printData(){
    for (int i = 0; i < size; i++)
    {
        if (strcmp(data[i],"")!=0)
        {
            /* code */
            printf("%d || %s\n",i,data[i]);
        }
        
        /* code */
    }
    
}

int main(){
    char name[12];
    int hashVal;
    while (1)
    // break jika user melakukan ctrl+c untuk terminate console 
    {
        /* code */
        scanf("%s",&name);
        hashVal = hashing(name[0]);
        printf("%d\n",hashVal);
        if (strcmp(data[hashVal],"")==0)
        {
            /* code */
            strcpy(data[hashVal],name);
        }else{
            // printf("ada data\n");
            int i = hashVal+1;
            int full = 0;
            while (strcmp(data[i],"")!=0)
            {
                /* code */
                if (i == hashVal)
                {
                    printf("data full\n");
                    full = 1;
                    break;
                /* code */
                }
                i = (i+1)%size;
            }
            strcpy(data[i],name);
        }
        system("cls");
        printData();
    }
    
    
    return 0;
    
}