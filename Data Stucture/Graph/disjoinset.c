#include <stdio.h>

#define SIZE 50

int parent[SIZE];
int size[SIZE];

void initParent(){
    for (int i = 0; i < SIZE; i++)
    {
        /* code */
        parent[i] = -1;
    }
    
}
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

// int find_set(int v) {
//     if (v == parent[v])
//         return v;
//     return find_set(parent[v]);
// }


int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// void union_sets(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     printf("root one: %d - root two: %d\n",a,b);
//     if (a != b) {
//         if (size[a] < size[b])
//             swap(&a, &b);
//         parent[b] = a;
//         size[a] += size[b];
//     }
// }
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    // printf("root one: %d - root two: %d\n",a,b);
    if (a != b)
        parent[b] = a;
}

void pathCompression(int a){
    if(a != parent[a]){
        parent[a] = find_set(parent[a]);
    }
}

void printData(){
    printf("----------- printing data ---------------\n");
    for (int i = 0; i < SIZE; i++)
    {
        /* code */
        // if (parent[i]!=-1)
        // {
        //     printf("%d with parent: %d\n",i,parent[i]);
        //     /* code */
        // }
        printf("%d ",parent[i]);
        
    }
    printf("\nthe size: \n");
    for (int i = 0; i < SIZE; i++)
    {
        /* code */
        // if (parent[i]!=-1)
        // {
        //     printf("%d with parent: %d\n",i,parent[i]);
        //     /* code */
        // }
        printf("%d ",size[i]);
        
    }
    printf("\n");
}

/*
    if parent[v] != findset(v)
    and findset(parent[v]) == findset(v)
    parent[v] = findset(v)
*/

int main(){
    // {1}
    initParent();
    make_set(1);
    // {1,2}
    printData();
    make_set(2);
    printData();
    union_sets(1,2);
    printData();
    // {3}
    make_set(3);
    printData();
    // {3,4}
    make_set(4);
    // {2,3}
    union_sets(3,4);
    printData();
    make_set(5);
    make_set(6);
    union_sets(5,6);
    printData();
    union_sets(2,4);
    printData();
    union_sets(2,5);
    printData();

    //naive approach
    for (int i = 0; i < SIZE; i++)
    {
        /* code */
        if (parent[i]!=-1)
        {
            /* code */
            pathCompression(i);
        }
    }
    
    printData();

    return 0;
}