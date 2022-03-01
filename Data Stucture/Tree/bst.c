#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    /* data */
    int key;
    struct tnode *left;
    struct tnode *right;
} * root;


struct tnode * createNode(int val){
    struct tnode *tmp = (struct tnode *) malloc(sizeof(struct tnode));
    tmp->key = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void inorder(int lev,struct tnode* root)
{
	if (root != NULL) {
		inorder(lev+1, root->left);
		printf("level: %d - data: %d\n", lev,root->key);
		inorder(lev+1, root->right);
	}
}


void preorder(int lev,struct tnode* root)
{
	if (root != NULL) {
		printf("level: %d - data: %d\n", lev,root->key);
		inorder(lev+1, root->left);
		inorder(lev+1, root->right);
	}
}

void insert(int val, struct tnode * node){
    if (!root)
    {
        /* code */
        root = createNode(val);
        return;
    }else
    {
        if (val < node->key)
        {
            if (!node->left)
            {
                /* code */
                struct tnode * tmp = createNode(val);
                node->left = tmp;
            }else{
                /* code */
                insert(val, node->left);
            }

        }else if(val > node->key){
            if (!node->right)
            {
                /* code */
                struct tnode * tmp = createNode(val);
                node->right = tmp;
            }else{
                /* code */
                insert(val, node->right);
            }
        }
        
    }
}

struct tnode * getMaxLeft(struct tnode * node){
    struct tnode * search = node;
    while (search->right)
    {
        /* code */
        search = search->right;
    }
    return search;
}


struct tnode * getMinRight(struct tnode * node){
    struct tnode * search = node;
    while (search->left)
    {
        /* code */
        search = search->left;
    }
    return search;
}

struct tnode * delete(int val, struct tnode * node){
    if (!root)
    {
        printf("empty tree");
        return NULL;
    }

    // cari dulu
    if (val > node->key)
    {
        /* code */
        node->right = delete(val, node->right);
    }else if(val < node->key){
        node->left = delete(val, node->left);
    }else{ 
        if (!node->left && !node->right)
        {
            /* code */
            free(node);
            return NULL;
        }else
        if (!node->left)
        {
            /* code */
            return node->right;
        }else if(!node->right){
            return node->left;
        }else{
            // double child
            struct tnode *tmp = getMaxLeft(node->left);
            node->key = tmp->key;
            node->left = delete(tmp->key,node->left);
        }
    }
    return node;
}

int main(int argc, char const *argv[])
{
    insert(30,root);
    insert(15,root);
    insert(7,root);
    insert(26,root);
    insert(19,root);
    insert(17,root);
    insert(21,root);
    insert(37,root);
    insert(34,root);
    insert(31,root);
    insert(45,root);
    insert(42,root);

    inorder(0,root);
    printf("\n\n");
    // 
    printf("after delete:\n");
    delete(30,root);
    inorder(0,root);

    printf("\n\n");
    // preorder(0,root);

    return 0;
}
