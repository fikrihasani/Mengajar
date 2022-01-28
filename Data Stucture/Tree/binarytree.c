#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode
{
    /* data */
    char data;
    struct tnode *left;
    struct tnode *right;
} *root;

struct tnode * newnode(char v){
    struct tnode *tmp =(struct tnode *) malloc(sizeof(struct tnode));
    tmp->data = v;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

char s[20];
int  p;

int is_operator(char c){
    char op[10] = {'+','*','/','-','^'};
    for (int i = 0; i < 10; i++)
    {
        /* code */
        if (op[i] == c)
        {
            /* code */
            return 1;
        }
        
    }
    return 0;
    
}
void f(struct tnode *curr) {
	if (is_operator(s[p]) ) {
		p++; 
        curr->left  = newnode(s[p]);
		f(curr->left);
		p++; 
        curr->right = newnode(s[p]);
		f(curr->right);
	}
}

void fpost(struct tnode *curr) {
	if (is_operator(s[p]) ) {
		p--; 
        curr->right = newnode(s[p]);
		fpost(curr->right);
		p--; 
        curr->left  = newnode(s[p]);
		fpost(curr->left);
	}
}

void prefix(struct tnode *curr) {
	printf( "%c", curr->data);
	if ( curr->left  != 0 ) prefix(curr->left);
	if ( curr->right != 0 ) prefix(curr->right);
}

void postfix(struct tnode *curr) {
    if ( curr->left  != 0 ) postfix(curr->left);
	if ( curr->right != 0 ) postfix(curr->right);
	printf( "%c", curr->data);
}

void infix(struct tnode *curr) {
		if ( is_operator(curr->data) ) printf( "(" );
		if ( curr->left != 0 ) infix(curr->left);
		printf( "%c", curr->data );
		if ( curr->right != 0 ) infix(curr->right);
		if ( is_operator(curr->data) ) printf( ")" );
	}


int main(){
    strcpy(s,"ab+cd-e/*");
    p = strlen(s)-1;
    // p = 0;
    root = newnode(s[p]);

    fpost(root);
    postfix(root);
    // infix(root);
    return 0;
}