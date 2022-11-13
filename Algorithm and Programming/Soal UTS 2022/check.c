#include <stdio.h>
#include <string.h>

int main(){
    char s[10000];
    int abj[26];
    int none0 = 0;
    int sum = 0;
    scanf("%s",s);
    for(int i = 0; i<26; i++)
        abj[i] = 0;
    for(int i = 0; i<strlen(s);i++){
        abj[s[i]-'a'] += 1;
        sum += 1;
    }
    int idxMax = s[0] - 'a';;
    int idxMin = idxMax;
    for(int i = 0; i<26;i++){
        if(abj[i]!=0){
            if(abj[idxMax] < abj[i])
                idxMax = i;
            if(abj[idxMin] > abj[i]){
                idxMin = i;
            }
            none0 +=1;
        }
    }
    int sumMax = 0;
    int sumMin = 0;
    if(none0 == 1 || idxMax == idxMin)
        printf("N/A\n");
    else if((sum - abj[idxMax])% (none0 - 1) == 0){
        printf("%c\n",idxMax+'a');
    }else if((sum - abj[idxMin])% (none0 - 1) == 0){
        printf("%c\n",idxMin+'a');
    }else{
        printf("N/A\n");
    }
//    bbbb
//    cccc
//    dddd
//    ee
}
