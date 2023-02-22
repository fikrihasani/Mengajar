#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    char data[10];
    int totalLen;
    struct tnode * left;
    struct tnode * right;
};

struct tnode * root = NULL;

struct tnode * initNode(char s[]){
    struct tnode *tmp = (struct tnode *)malloc(sizeof(struct tnode));
    tmp->left = tmp->right = NULL;
    strcpy(tmp->data,s);
    tmp->totalLen = 0;
}
void insert(struct tnode * curr, struct tnode * tmp){
    if(!root){
        root = tmp;
    }else{
        if(strcmp(curr->data,tmp->data) > 0 && curr->left == NULL){
            curr->left = tmp;
        }else if(strcmp(curr->data, tmp->data) < 0 && curr->right == NULL){
            curr->right = tmp;
        }else if(strcmp(curr->data,tmp->data) > 0){
            insert(curr->left, tmp);
        }else if(strcmp(curr->data, tmp->data) < 0){
            insert(curr->right, tmp);
        }
    }
}

int updateTotalLength(struct tnode * curr){
    if(!curr){
        return 0;
    }else{
        curr->totalLen = updateTotalLength(curr->left) + updateTotalLength(curr->right);
        return strlen(curr->data) + curr->totalLen;
    }
}
void inorder(struct tnode *curr){
    if(curr->left) inorder(curr->left);
    printf("%s ",curr->data);
    if(curr->right) inorder(curr->right);
}

void inorderLen(struct tnode *curr){
    if(curr->left) inorderLen(curr->left);
    printf("%d ",curr->totalLen);
    if(curr->right) inorderLen(curr->right);
}

struct tnode * getMaxLeft(struct tnode * curr){
    //get left child dulu
    struct tnode * iter = curr->left;
    //melakukan looping ke kanan sampai tidak ada right child
    while(iter->right){
        iter = iter->right;
    }
    return iter;
}

struct tnode * delete(struct tnode * curr, char val[]){
    //cek apakah tree kosong atau tidak
    if(!root){
        return NULL;
    }
    //kondisi untuk handle data yang tidak ada di dalam tree
    if(strcmp(curr->data, val) > 0  && !curr->left || strcmp(curr->data,val) < 0  && !curr->right){
        return curr;
    }
    //recursive ke dalam tree nya.
    if(strcmp(curr->data, val) > 0){
        curr->left = delete(curr->left, val);
    }else if(strcmp(curr->data,val) < 0){
        curr->right = delete(curr->right, val);
    }else{
        //cek untuk berdasarkan kondisi yang telah dipelajari
        //kond 1 , merupakan leaf
        if(!curr->left && !curr->right){
            free(curr);
            return NULL;
        }else if(!curr->left){
            //ambil right child
            return curr->right;
        }else if(!curr->right){
            //ambil left
            return curr->left;
        }else{
            //jika ada 2 anak
            //dapatkan maximum node untuk left child
            struct tnode * tmp = getMaxLeft(curr);
            //copy isinya
            strcpy(curr->data,tmp->data);
            //lakukan proses ulang untuk? left child
            curr->left = delete(curr->left,tmp->data);
        }
    }
    return curr;
}
int main(){
    char s[10];
    int count;
    scanf("%d",&count);
    int i;
    for (i = 0; i < count; i++)
    {
        /* code */
        scanf("%s",s);
        struct tnode * tmp = initNode(s);
        insert(root,tmp);
    }
    updateTotalLength(root);
    inorder(root);
    printf("\n");
    inorderLen(root);
    delete(root,"gana");
    updateTotalLength(root);
    inorder(root);
    printf("\n");
    inorderLen(root);
    printf("\n");
    return 0;
}