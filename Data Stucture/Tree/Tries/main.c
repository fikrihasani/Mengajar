#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trie {
	char chr;
	int  word;
	struct trie* edge[128];
} *root = 0;

char s[100] = {"halllo"}; // global

struct trie* newnode(char x) {
	struct trie* node = (struct trie*)malloc(sizeof(struct trie));
	node->chr  = x;
	node->word = 0;
	for (int i = 0; i < 128; i++ )
		node->edge[i] = 0;
	return node;
}

void insert(struct trie *curr, char *p) {
	if ( curr->edge[*p] == 0 )
		curr->edge[*p] = newnode(*p);
	if ( *p == 0 ) curr->word = 1; else insert(curr->edge[*p],p+1);
}



void find(struct trie *curr, int x) {
	if ( curr->word == 1 ) {
		s[x] = 0;
        printf("s: %s\n",s);
		// puts( s );
	}
	for (int i = 0; i < 128; i++ )
		if ( curr->edge[i] != 0 ) {
			s[x] = i;
			find(curr->edge[i],x+1);
		}
}


int main(){
    root = (struct trie*)malloc(sizeof(struct trie));
    root->chr = ' ';
    root->word = 0;

    insert(root, s);

    char st[100] = "ha";


    int  i, n, okay;
    struct trie *curr;
    n    = strlen(st);
    okay = 1;
    curr = root;
    for ( i = 0; i < n && okay == 1; i++ )
        if ( curr->edge[st[i]] == 0 ) okay = 0;
        else curr = curr->edge[st[i]];
    if ( okay ) find(curr,n);
    return 0;

}