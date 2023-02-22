#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int val;
    struct tnode *left;
    struct tnode *right;
};
struct tnode *root = NULL;
struct tnode * newnode(int val){
    struct tnode *tmp = (struct tnode *)malloc(sizeof(struct tnode));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

int delExist = 1;

//search
struct tnode * search(struct tnode * curr, int x){
    //cek kondisi untuk data tidak ada
    if (curr == NULL) {
        return NULL;
    }else if (x < curr->val)
    {
        /* code */
        search(curr->left, x);
    }else if (x > curr->val){
        //jika ke x > curr->val, maka ke kanan
        search(curr->right, x);
    }else if(x == curr->val){
        //jika x == curr->val maka return
        return curr;
    }
    

}

//insert
void insert(struct tnode *curr,int x){
    if(root == NULL){
        root = newnode(x);
    }else {
        if(x < curr->val  && curr->left == NULL){
            //jika x < curr val dan curr adalah leaf, insert
            curr->left = newnode(x);

        }else if (x > curr->val && curr->right == NULL){
            //jika x > curr val dan curr adalah leaf, insert
            curr->right = newnode(x);

        }else if(x < curr->val){
        //jika x < curr val, ke kiri
            insert(curr->left, x);

        }else if(x > curr->val){
        //jika x > curr val, ke kanan. 
             insert(curr->right, x);
        }
    }
    
}
void inorder(int lev, struct tnode *curr){
    if(curr->left != NULL) inorder(lev+1, curr->left);
    printf("level: %d - data: %d\n",lev,curr->val);
    if(curr->right !=NULL) inorder(lev+1, curr->right);
}

//fungsi untuk mendapatkan maximum dari left child
struct tnode * getMaxLeft(struct tnode * curr){
    //get left child dulu
    struct tnode * iter = curr->left;
    //melakukan looping ke kanan sampai tidak ada right child
    while(iter->right){
        iter = iter->right;
    }
    return iter;
}

struct tnode * delete(struct tnode * curr, int val){
    //cek apakah tree kosong atau tidak
    if(!root){
        return NULL;
    }
    //kondisi untuk handle data yang tidak ada di dalam tree
    if(val < curr->val && !curr->left || val > curr->val && !curr->right){
        delExist = 0;
        return curr;
    }
    //recursive ke dalam tree nya.
    if(val < curr->val){
        curr->left = delete(curr->left, val);
    }else if(val > curr->val){
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
            curr->val = tmp->val;
            //lakukan proses ulang untuk? left child
            curr->left = delete(curr->left,tmp->val);
        }
    }
    return curr;
}
//deletenya
int main(){
    int x;
    insert(root, 5);
    insert(root, 18);
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    inorder(0,root);
    printf("\n");
    printf("%d\n",getMaxLeft(root)->val);
    printf("input integer data to be deleted: ");
    int y;
    scanf("%d",&y);
    //delete node dengan data y
    delete(root, y);
    inorder(0,root);
    printf("data ada? %d",delExist);
    printf("\n");
    return 0;
}