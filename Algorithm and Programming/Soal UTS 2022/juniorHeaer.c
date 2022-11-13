#include <stdio.h>

int main(){
    int m;
    int heal;
    scanf("%d %d",&m,&heal);
    int matrix[m][m];
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++)
            scanf("%d",&matrix[i][j]);
    }
    int idxMinI= 0;
    int idxMinJ = 0;
    for(int i =0; i<m; i++){
        for(int j = 0; j<m; j++)
            if(matrix[i][j] < matrix[idxMinI][idxMinJ]){
                idxMinI = i;
                idxMinJ = j;
            }
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++)
            if(i == idxMinI|| j == idxMinJ){
                matrix[i][j] += heal;
            }
    }
    matrix[idxMinI][idxMinJ] += heal*heal;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++)
            if(matrix[i][j] >= 5000)
                printf("%d ",5000);
            else
                printf("%d ",matrix[i][j]);
    }
    printf("\n");
    return 0;
}
