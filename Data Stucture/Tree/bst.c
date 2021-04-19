#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    /* data */
    int data;
    struct tnode *left;
    struct tnode *right;
} *root;

int maxLevel = 1;

struct tnode * newnode(int x){
    struct tnode *tmp = (struct tnode *)malloc(sizeof(struct tnode));
    tmp->data = x;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void insert(int level, struct tnode *curr, int x){
    if(level > maxLevel){
        printf("tidak dapat menambahkan data %d\n",x);
    }else{
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
            insert(level+1, curr->left,x);
        }else if(curr->right != NULL && x > curr->data){
            insert(level+1, curr->right,x);
        }
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
    insert(0,root, 10);
    insert(0,root, 8);
    insert(0,root, 20);
    insert(0,root, 7);
    insert(0,root, 4);
    print(0,"center",root);
}


