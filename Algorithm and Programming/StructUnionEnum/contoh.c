// tipe data boolean , true atau false
// enum dan typedef

#include <stdio.h>

enum boolVal {false, true};
typedef enum boolVal boolean;

int main(){
    boolean check;
    check = false;
    check = true;
    if(check){
        printf("check is true");
    }else{
        printf("check is false");
    }
}