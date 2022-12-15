#include <stdio.h>

int main(){
    int p;
    int v;
    int y;
    int tmp;
    scanf("%d %d %d",&p,&v,&y);
    tmp = v; 
    for(int i=0; i<y; i++){
        int inc = (tmp/p) * 0.05;
        tmp += inc;
        printf("%d %d\n",inc,tmp);
    }
    printf("%d\n",tmp);
    return 0;
}