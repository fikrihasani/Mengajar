#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void init_g(int *g, int n_nodes){
    *g = malloc((n_nodes*n_nodes)*sizeof(int));
    for (int i = 0; i < n_nodes; i++)
    {
        /* code */
        for (int j = 0; i < n_nodes; i++)
        {
            /* code */
            printf("Input node weight of node %d and %d", i, j);
            int val;
            scanf("%d",val);
            g[i][j] = 
        }
        
    }
    
}