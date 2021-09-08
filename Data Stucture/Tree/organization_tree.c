#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode
{
    /* data */
    char nama[26];
    char jabatan[26];
    struct tnode *right;
    struct tnode *left;
} *tree, *tmp;

struct tnode * newnode(char nama[], char jabatan[]){
    struct tnode *node = (struct tnode *)malloc(sizeof(struct tnode));
    strcpy(node->nama,nama);
    strcpy(node->jabatan,jabatan);
    node->right = NULL;
    node->left = NULL;
    return node;
}

void print(int level, char *pos, struct tnode *curr) {
	printf( "level: %d - %s - %s\n", level, pos, curr->nama );
	if ( curr->left  != 0 ) print(level+1, "left",curr->left);
	if ( curr->right != 0 ) print(level+1, "right",curr->right);
}

// depth first search
int getLevel(int level, char nama[], struct tnode *curr){
    if(curr == NULL){
        return -1;
    }else if(strcmp(curr->nama,nama) == 0){
        return level;
    }else{
        if(getLevel(level+1,nama,curr->right) != -1){
            return getLevel(level+1,nama,curr->right);
        }
        return getLevel(level+1,nama, curr->left);
            
    }
}

void compare(char personA[], char personB[]){
    int levelA = getLevel(0,personA,tree);
    // levelA = 0
    int levelB = getLevel(0,personB,tree);
    // levelB = 2
    if (levelA == -1 || levelB == -1)
    {
        /* code */
        printf("Orangnya tidak ada");
    }else{
        if (levelA == levelB)
        {
            /* code */
            printf("%s memiliki jabatan sama dengan %s",personA, personB);
        }else if(levelA > levelB){
            printf("%s memiliki jabatan dibawah %s",personA, personB);
        }else{
            printf("%s memiliki jabatan diatas %s",personA, personB);
        }
    }
}

int main(){
    tree = newnode("saya","ketua");
    tmp = newnode("andi","ketua cabang 1");
    tree->left = tmp;
    tmp = newnode("koko","ketua cabang 2");
    tree->right = tmp;
    tmp = newnode("jali","ketua div cabang 1");
    tree->left->left = tmp;
    print(0,"root",tree);

    compare("saya","jali");
    free(tmp);
    free(tree);
    return 1;
}
