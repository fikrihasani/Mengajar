#include <stdio.h>

int main(){
    int m;
    int damage;
    scanf("%d %d",&m,&damage);
    int matrix[m][m];
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++)
            scanf("%d",&matrix[i][j]);
    }
    int idxMaxI = 0;
    int idxMaxJ = 0;
    for(int i =0; i<m; i++){
        for(int j = 0; j<m; j++)
            if(matrix[i][j] > matrix[idxMaxI][idxMaxJ]){
                idxMaxI = i;
                idxMaxJ = j;
            }
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++)
            if(i == idxMaxI || j == idxMaxJ){
                matrix[i][j] -= damage;
            }
    }
    matrix[idxMaxI][idxMaxJ] -= damage*damage;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++)
            if(matrix[i][j] <= 0)
                printf("overkill ");
            else
                printf("%d ",matrix[i][j]);
    }
    printf("\n");
    return 0;
}
