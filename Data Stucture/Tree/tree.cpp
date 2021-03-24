#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
	char chr;
	struct tnode *left;
	struct tnode *right;
};


struct tnode *root = NULL;

char s[10];
int  p = 0;

int is_operator(char c){
    if ((c - '+') == 0 || (c - '-') == 0 || (c - '*') == 0 || (c - '/')== 0)
    {
        /* code */
        return 1;
    }
    return 0;
}

struct tnode * newnode(char c){
    struct tnode *tmp = (struct tnode *)malloc(sizeof(struct tnode));
    tmp->chr = c;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void f(struct tnode *curr) {
	if (is_operator(s[p])) {
		p++; 
        printf("current pointer position: %d - char: %c - ",p,s[p]);
        curr->left  = newnode(s[p]);
        printf("now go left\n");
		f(curr->left);
		p++; 
        printf("current pointer position: %d - char: %c - ",p,s[p]);
        curr->right = newnode(s[p]);
        printf("now go right\n");
		f(curr->right);
	}else{
        printf("char: %c\n",s[p]);
    }
}
void prefix(struct tnode *curr) {
	printf( "%c\n", curr->chr );
	if ( curr->left  != 0 ) prefix(curr->left);
	if ( curr->right != 0 ) prefix(curr->right);
}


int main(){
    scanf("%s",&s);
    struct tnode *root = newnode(s[0]);
    f(root);
    prefix(root);
    return 0;
}
