//contoh fgets
#include <stdio.h>

int main(){
    FILE * fp;

    char tmp[80];
    fp = fopen("data.txt","r");

    if (!fp)
    {
        /* code */
        printf("cannot open file");
    }else{
        while (fgets(tmp,80,fp))
        {
            /* code */
            printf("%s",tmp);
        }
    }
    return 0;


}