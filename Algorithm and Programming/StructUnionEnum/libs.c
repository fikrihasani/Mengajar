#include <stdio.h>

struct book{
    char title[10];
    char author[10];
};

struct lib{
    char name[10];
    int numBook;
    struct book books[5];
};

void menu(){
    printf("1. insert data");
    printf("2. show data");
    printf("3. exit");
}
int main(){
    struct lib libraries[2];
    strcpy(libraries[0].name,"perpus1");
    strcpy(libraries[1].name,"perpus2");
    int inp = 0;
    do
    {
        menu();
        printf("masukkan pilihan: ");
        scanf("%d",&inp);
        switch (inp)
        {
        case 1:
            printf("Input perpus: ");
            char tmp[10];
            scanf("%s",tmp);
            if(strcmp(tmp,"perpus1") == 0){
                printf("Input nama buku perpus: ");
                scanf("%s",libraries[0].books[0].title);
                printf("Input nama penulis buku: ");
                scanf("%s",libraries[0].books[0].author);
            }else{

            }

            break;
        
        case 2:
            printf("Perpus: %s\n",libraries[0].name);
            printf("Buku: %s\n",libraries[0].books[0].title);
            printf("Penulis: %s\n",libraries[0].books[0].author);
            break;

        default:
            break;
        }
    } while (inp!=3);
    



    
    return 0;

}