#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int val;
    struct tnode *left;
    struct tnode *right;
    int height;
};
struct tnode *root = NULL;
struct tnode * newnode(int val){
    struct tnode *tmp = (struct tnode *)malloc(sizeof(struct tnode));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->height = 1;
    return tmp;
}

int delExist = 1;

int height(struct tnode * node){
    if(node == NULL){
        return 0;
    }else{
        return node->height;
    }
}

int max(int a, int b){
    return (a > b) ? a : b;
}

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

int updateHeight(struct tnode * node){
    if(!node) return 0;
    else if(!node->left && !node->right)
        return 1;
    else
        return 1 + max(updateHeight(node->left),updateHeight(node->right));
    
}
//right rotate for left left case
struct tnode  * rightRotate(struct tnode * node){
    struct tnode * a = node->left;
    struct tnode * c = a->right;
    // //swap
    a->right = node;
    node->left = c;

    //update height
    if(node)
        node->height = updateHeight(node);
    if(a)
        a->height = updateHeight(a);
    if(c)
        c->height = updateHeight(c);
    
    return a;
}

struct tnode * leftRotate(struct tnode * node){
    struct tnode * a = node->right;
    struct tnode * c = a->left;

    a->left = node;
    node->right = c;
    if(node)
        node->height = updateHeight(node);
    if(a)
        a->height = updateHeight(a);
    if(c)
        c->height = updateHeight(c);
    return a;
}

//insert
struct tnode * insert(struct tnode *curr,int x){
    if(!curr)
        return newnode(x);
    if(x < curr->val){
        curr->left = insert(curr->left, x);
    }else if(x > curr->val){
        //jika x > curr val, ke kanan. 
        curr->right = insert(curr->right, x);
    }else{
        return curr;
    }
    curr->height = updateHeight(curr);
    if(height(curr->left) - height(curr->right) > 1){
        return rightRotate(curr);
    }else if(height(curr->left) - height(curr->right) < 0){
        return leftRotate(curr);
    }
    return curr;
}
void inorder(int lev, struct tnode *curr){
    if(curr->left != NULL) inorder(lev+1, curr->left);
    printf("level: %d - data: %d - height: %d\n",lev,curr->val, curr->height);
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

    // root = insert(root, 50);
    // root = insert(root, 30);
    // root = insert(root, 20);
    // root = insert(root, 8);
    // root = insert(root, 7);
    // root = insert(root, 2);

    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);

    inorder(0,root);
    return 0;
}