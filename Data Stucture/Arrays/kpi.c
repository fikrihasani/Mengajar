#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct emp
{
    /* data */
    char name[100];
    char department[100];
}eDetail;

typedef struct comp{
    //1 - 6
    float compA;
    float compB;
    float compC;
    float compD;
    float compE;
}kpiComp;

typedef struct kpi
{
    /* data */
    int idEmployee;
    eDetail empDetail;
    kpiComp components;
    //average setiap komponen
    float kpiScore;

}KPI;

void inputData(KPI *empKpi){
    printf("input data: \n");
    printf("id employee: "); scanf("%d",&empKpi->idEmployee);
    getchar();
    printf("employee name: "); scanf("%[^\n]",empKpi->empDetail.name);
    getchar();
}

void printData(KPI empKpi){
    printf("id employee: %d\n",empKpi.idEmployee);
    printf("employee name: %s\n",empKpi.empDetail.name);
    getchar();
    getchar();
}
void menu(){
    system("CLS");
    printf("1. Input Data\n");
    printf("2. Print Data\n");
    printf("0. exit\n");
}
int main(){
    KPI empKPI;
    int inp = 1;
    while (inp != 0)
    {
        menu();
        scanf("%d",&inp);
        switch (inp)
        {
        case 1:
            inputData(&empKPI);
            break;
        
        case 2:
            printData(empKPI);
            break;
        
        default:
            break;
        }
        /* code */
    }
    printf("THANK YOU");
    
}