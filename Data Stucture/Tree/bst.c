#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    /* data */
    int data;
    struct tnode *left;
    struct tnode *right;
} *root;

int maxLevel = 4;

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


void deleteNodeRecursively(struct tnode* curr, struct tnode* parent){
    // condition 1 = only one node
    printf("going here inside, root: %d\n",root->data);
    if (curr->left == NULL && curr->right == NULL)
    {
        printf("delete leaf node\n");
        if (curr == root)
        {
            /* code */
            free(curr);
            root = NULL;
            printf("The root");
        }
        printf("going here inside, root: %d\n",root->data);

        // else{
        //     if (curr == parent->left)
        //     {
        //         parent->left = NULL;
        //         /* code */
        //     }else{
        //         parent->right = NULL;
        //     }
        //     struct tnode *tmp = curr;
        //     free(tmp);            
        // }
    }else if(curr->left == NULL){
        if (curr == root)
        {
            /* code */
            root = curr->right;
        }
        else if(curr->data > parent->data)
        {
            /* code */
            parent->right = curr->right;
        }else
        {
            parent->left = curr->right;
        }
        free(curr);
    }else if(curr->right = NULL)
    {
        if (curr == root)
        {
            /* code */
            root = curr->left;
        }
        else if(curr->data > parent->data)
        {
            /* code */
            parent->right = curr->left;
        }else
        {
            parent->left = curr->left;
        }
        
        free(curr);
        
    }else{
        printf("going here, the data: %d\n",curr->data);
        print(0,"center",root);
        printf("\n");
        struct tnode * p = curr->left;
        struct tnode * pp = curr;
        while (p->right != NULL)
        {
            /* code */
            pp = p;
            p = p->right;
        }
        printf("going here, curr: %d\n",curr->data);
        printf("going here, root: %d\n",root->data);
        printf("going here, parent: %d\n",pp->data);
        printf("going here, data: %d\n",p->data);
        int data = p->data;
        printf("going here, root: %d\n",root->data);
        deleteNodeRecursively(p,pp);
        printf("going here after, root: %d\n",root->data);
        print(0,"center",root);
        printf("\n");
        curr->data = data;
    }
        
}

// complete it yourself
void deleteNode(struct tnode *root, int x){
    struct tnode *curr = root;
    struct tnode *parent = NULL;
    while(curr != NULL){
        if(x == curr->data) break;
        parent = curr;
        curr = ( x < curr->data) ? curr->left : curr->right;
    }
    printf("this is the data %d\n",curr->data);
    print(0,"center",root);
    // printf("this is the parent %d\n",parent->data);


    if (curr != NULL)
    {
        /* code */
        deleteNodeRecursively(curr,parent);
    }

}


void main(){
    insert(0,root, 50);
    insert(0,root, 30);
    insert(0,root, 40);
    insert(0,root, 70);
    insert(0,root, 60);
    insert(0,root, 80);

    print(0,"center",root);
    deleteNode(root,30);
    print(0,"center",root);
}


