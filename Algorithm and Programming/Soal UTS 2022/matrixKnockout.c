#include <stdio.h>

int main(){
    int m;
    scanf("%d",&m);
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
                continue;
            }else{
                printf("%d ",matrix[i][j]);
            }
    }
    printf("\n");
    return 0;
}
