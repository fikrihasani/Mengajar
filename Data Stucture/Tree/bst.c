#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    /* data */
    int data;
    struct tnode *left;
    struct tnode *right;
} *root;

struct tnode * newnode(int x){
    struct tnode *tmp = (struct tnode *)malloc(sizeof(struct tnode));
    tmp->data = x;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void insert(struct tnode *curr, int x){
    if (root == NULL)
    {
        /* code */
        root = newnode(x);
    }else{
        if (curr->left == NULL && x < curr->data)
        {
            /* code */
            struct tnode *tmp = newnode(x);
            curr->left = tmp;
        }else if(curr->right == NULL && x > curr->data){
            struct tnode *tmp = newnode(x);
            curr->right = tmp;
        }else if(curr->left != NULL && x < curr->data){
            insert(curr->left,x);
        }else if(curr->right != NULL && x > curr->data){
            insert(curr->right,x);
        }
    }
}

void print(int level, char *pos, struct tnode *curr) {
	printf( "level: %d - %s - %d\n", level, pos, curr->data );
	if ( curr->left  != 0 ) print(level+1, "left",curr->left);
	if ( curr->right != 0 ) print(level+1, "right",curr->right);
}

// complete it yourself
void deleteNode(){


}

void main(){
    struct tnode *curr = root;
    insert(curr, 10);
    curr = root;
    insert(curr, 8);
    curr = root;
    insert(curr, 20);
    curr = root;
    insert(curr, 7);
    print(0,"center",root);
}


