#include <stdio.h>

int main(){
    enum workday {mon, tue, wed, thurs, fri};
    enum workday days;
    days = fri;
    printf("%d\n",days);
}