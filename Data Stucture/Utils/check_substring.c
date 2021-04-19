#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int checkSubstring(char a[], char b[]){
    for (int i = 0; i < (strlen(a) - strlen(b)); i++)
    {
        if (a[i] == b[0] && a[i+(strlen(b)-1)] == b[strlen(b)-1])
        {
            int count = i;
            int j = 0;
            while (a[count] == b[j] && j < strlen(b))
            {
                count++;
                j++;
            }
            if(count == strlen(b)){
                return 1;
            }
        }
    }
    return 0;    
}

int main(){
    char str[200];
    char substr[20];
    printf("Input string: ");
    gets(str);
    printf("Input substring to find: ");
    gets(substr);
    int found = checkSubstring(str, substr);
    printf("%d",found);
}