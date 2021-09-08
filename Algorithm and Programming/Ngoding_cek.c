#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char nama [50];
    char kelas [4];
    char codeSiswa [10000];
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
    strcpy()
    // printf("Kelas: ");
    // scanf("%[^\n]",&kelas);
    // printf("Nilai Tugas: ");
    // scanf("%f",&tugas);
    // printf("Nilai Mid: ");
    // scanf("%f",&mid);
    // printf("Nilai UAS: ");
    // scanf("%f",&uas);
    // printf("Data: ");
    printf("%s\t%d\t%s\t%f\t%f\t%f",nama,tahun,kelas,tugas,mid,uas);
    return 0;    
}
