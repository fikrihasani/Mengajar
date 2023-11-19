#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26
//
struct TrieNode{
    struct TrieNode * children[SIZE];
    //tanda bahwa karakter tersebut merupakabn akhir dari sebuah kata
    int isEndofWord;
};

//init node untuk trie
struct TrieNode * getNode(){
    //inisasi size memory
    struct TrieNode * pNode  = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    //
    int i;
    pNode->isEndofWord = 0;
    for(i = 0; i < SIZE; i++){
        pNode->children[i] =NULL;
    }
    return pNode;
}

//insert key atau string kata ke dalam trie
void insert(struct TrieNode * root, char * key){
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode * pCrawl = root;

    for(level = 0; level < length; level++){
        index = key[level] - 'a';
        //jika array pada index NULL, berarti ada child baru
        if(pCrawl->children[index] ==NULL){
            pCrawl->children[index] = getNode();
        }

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndofWord = 1;
}

// returns 1 jika katanya ada di dalam trie, dan 0 jika tidak ada di dalam trie
int search(struct TrieNode * root, char * key){
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode * pCrawl = root;

    for(level = 0; level < length; level++){
        index = key[level] - 'a';
        if(pCrawl->children[index] == NULL) return 0;
        pCrawl = pCrawl->children[index];
    }
    return pCrawl->isEndofWord;

}

int main(){
    char keys[][10] ={"buku","budi","celana","kolak","pensil"};

    struct TrieNode * root = getNode();

    int i;
    for(i = 0; i < 5; i++){
        insert(root, keys[i]);
    }

    char key[] = "bu";
    printf("%s -> %d\n",key,search(root,key));
    return 0;
}

