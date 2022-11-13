#include <stdio.h>

int main(){
    //n < 10000;
    int n;
    scanf("%d",&n);
    char s[n*2];
    int pair = 0;
    int cNonPair = 0;
    int pairPos[n*2];
    int nonPair[n*2];
    for(int i =0; i<n*2; i++){
        pairPos[i] =0;
    }
    scanf("%s",s);
    int length = strlen(s);
    int iter = 0;
    for(int i = 0; i<length; i++){
        if(i<length-1){
            if(s[i] == s[i+1]){
                pairPos[i] = 1;
                pairPos[i+1] = 1;
                pair += 1;
                i+=1;
            }else{
                nonPair[i]+=1;
            }
        }
    }
    for(int i = 0; )
    printf("%d %d",pair,cNonPair);
    printf("\n");
//  [[]]]
    return 0;
}
