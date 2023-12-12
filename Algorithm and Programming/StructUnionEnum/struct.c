#include <stdio.h>
#include <string.h>

struct address{
    char city[10];
    char street[30];
};

struct dataMhs
{
    /* data */
    char nama[26];
    float nilai;
    struct address alamat;
};

//typedef. merubah tipe data ke alias
// typedef struct dataMhs mhs;

int main(){
    //var data dg tipe data datamhs
    // struct dataMhs data
    struct dataMhs data[] = {
        {"dinda",10.5,{"ponti","dekat mujahidin"}},
        {"aliong",80,{"ponti","pasar tengah"}}
    };
    // baca data baru dari scanf

    scanf("%s",data[1].nama);
    scanf("%f",&data[1].nilai);
    scanf("%s",data[1].alamat.city);

    printf("nama: %s\n",data[0].nama);
    printf("nilai: %f\n",data[0].nilai);
    printf("kota: %s\n",data[0].alamat.city);


    return 0;


}