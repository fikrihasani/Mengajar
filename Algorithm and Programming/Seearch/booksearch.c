#include <stdio.h>

struct book{
    int id;
    char title[20];
    char author[20];
};

//default linear search
//return index posisi value yang dicari
struct book linear(struct book arr[],int left, int right, int target){
    while(left<=right){
        int mid = left + (right - left) / 2;

        if(arr[mid].id == target){
            return arr[mid];
        }else if(arr[mid].id < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    struct book dummy = {-1,"data not found","author not found"};
    return dummy;
}

int main(){
    int n = 2;
    struct book books[]={
        {1,"title1","author1"},
        {2,"title2","author2"},
        {3,"title3","author3"}
    };

    int value;
    scanf("%d",&value);
    struct book find = linear(books, 0, 2, value);
    if(find.id != -1){
        printf("%d\n%s\n%s\n",find.id,find.title,find.author);
    }else{
        printf("id not exist in array");
    }
    return 0;

}