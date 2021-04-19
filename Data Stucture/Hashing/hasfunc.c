#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100


// midsquare with int to string to int
int midSquare(int key){
    long square = key*key;
    char digit[1000];
    sprintf(digit, "%d",square);
    int pos;
    int length = 2;
    char subs[length];

    if (strlen(digit)%2 == 0)
    {
        pos = (strlen(digit)/2)-1;

    }else{
        pos = (strlen(digit)/2);
    }

    int j = 0;
    for (int i = pos; i < (pos+length); i++)
    {
        subs[j] = digit[i];
        j++;
    }
    subs[length] = '\0';
    
    return atoi(subs);
    
}

// division
int division(int key){
    return key % size;
}

// convert string to key
int stringToKey(char s[]){

    int tot = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        tot = tot + s[i];
    }
    return tot;
}

int folding(int key){
    // 
    char digit[1000];
    sprintf(digit, "%d",key);

    // ukuran sub digit
    int length = 2;
    int n = strlen(digit);

    int i= 0;
    int k = 0;
    int total = 0;

    // kita loop sebanyak panjang nya
    while (i<n)
    {
        // dapetin subdigit
        char subdigit[length];
        for (int j = 0; j < length; j++)
        {
            subdigit[j] = digit[i];      
            i++;
        }
        subdigit[length] = '\0';

        // ubah ke int dan masukin ke total. 
        total = total + atoi(subdigit);
    }
    return total % size;
    
}


int main(){
    long key;
    key = stringToKey("cobb");
    int hashVal = midSquare(key);
    printf("%d\n",hashVal);
    printf("%d\n",folding(5678));
    printf("%d\n",folding(34567));

    return 0;
}