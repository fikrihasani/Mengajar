#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n_data = 100;
int main(){
    struct datas
    {
        /* data */
        char nama[26];
        float compa;
        float compb;
        float compc;

    } mahasiswa[n_data];
    
    FILE *fp = fopen("data.txt","r");
    if (fp == NULL)
    {
        /* code */
        printf("File not existed\n");
        return -1;
    }else{
        int a, b, c,i,r;
        while ((r = fscanf(fp, "%d,%d,%d", &a, &b, &c)) != EOF) {
            printf("%d = \n",r);
            i++;
            printf("Values: \t%d\t%d\t%d\n", a,b,c);            
        }
    }
  	char nama [50];
    char kelas [4];
    char codeSiswa[10000];
    float tugas;
    float mid;
    float uas;
    float total;
    int tahun;
    printf("Input data baru: \n");
    printf("Nama: ");
    scanf("%[^\n]",&nama);
    printf("Kelas: ");
    scanf("%s",&kelas);
    printf("Tahun Masuk: ");
    scanf("%d",&tahun);
    strcpy(codeSiswa,"");
    // printf("Kelas: ");
    // scanf("%[^\n]",&kelas);
    // printf("Nilai Tugas: ");
    // scanf("%f",&tugas);
    // printf("Nilai Mid: ");
    // scanf("%f",&mid);
    // printf("Nilai UAS: ");
    // scanf("%f",&uas);
    // printf("Data: ");
    printf("%s\t%s\t%d\t%s\t%f\t%f\t%f",codeSiswa,nama,tahun,kelas,tugas,mid,uas);
    return 0;  
}
