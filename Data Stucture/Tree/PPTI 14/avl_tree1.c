#include <stdio.h>
#include <stdlib.h>

struct tnode{
    int value;
    struct tnode * right;
    struct tnode * left;
    int height;
};

struct tnode * root = NULL;

struct tnode * initNode(int val){
    struct tnode * tmp = (struct tnode *)malloc(sizeof(struct tnode));
    tmp->value = val;
    tmp->right = tmp->left = NULL;
    tmp->height = 1;
    return tmp;
}

int height(struct tnode * node){
    if(!node) return 0;
    return node->height;
}

int max(int a, int b){
    return (a > b) ? a : b;
}



int updateHeight(struct tnode * node){
    //algorithm
    //kondisi berhenti, dilihat lagi karakteristik dari AVL tree (node null = height 0, leaf = height 1)
    //recursive 
    return max(height(node->left),height(node->right)) + 1;
}


//ll 
struct tnode * rightRotate(struct tnode * t){
    struct tnode * s = t->left;
    struct tnode * b = s->right;

    //lepas pasang
    s->right = t;
    t->left = b;

    //update height
    t->height = updateHeight(t);
    s->height = updateHeight(s);

    return s;
}

//rr
struct tnode * leftRotate(struct tnode * t){
    struct tnode * s = t->right;
    struct tnode * b = s->left;

    //lepas pasang
    s->left = t;
    t->right = b;

    //update height
    t->height = updateHeight(t);
    s->height = updateHeight(s);

    return s;
}
struct tnode * insert(struct tnode * curr, int x){
    //jika curr = null
    if(!curr){
        return initNode(x);
    }else{
        //jika dia kurng dari
        if(x < curr->value){
            curr->left = insert(curr->left, x);
        }else if(x > curr->value){
            curr->right = insert(curr->right, x);
        }else{
            return curr;
        }
    }
    curr->height = updateHeight(curr);

    //cek balance factor
    if(height(curr->left) - height(curr->right) > 1 && x > curr->left->value){
        //left right case
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }else if(height(curr->right) - height(curr->left) > 1 && x < curr->right->value){
        //right left
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }else if(height(curr->left) - height(curr->right) > 1){
        return rightRotate(curr);
    }else if(height(curr->right) - height(curr->left) > 1){
        return leftRotate(curr);
    }

    return curr;
}

//print inorders
void inorder(int lev, struct tnode *curr){
    if(curr->left != NULL) inorder(lev+1,curr->left);
    printf("level: %d - data: %d - height: %d\n",lev, curr->value, curr->height);
    if(curr->right != NULL) inorder(lev+1,curr->right);
}
int main(){
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 35);

    inorder(0,root);
    return 0;
}