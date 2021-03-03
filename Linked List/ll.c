#include <stdio.h>
#include <stdlib.h>

struct Node { 
    int data; 
    struct Node *next; 
}; 
  
// This function prints contents of linked list starting from 
// the given node 

struct Node * createNode (int val, struct Node *n){
    n = (struct Node*)malloc(sizeof(struct Node)); 
    n->data = val;
    n->next = NULL;
    return n;
}



void printList(struct Node *n) 
{ 
    while (n != NULL) { 
        printf(" %d ", n->data); 
        n = n->next; 
    } 
} 

void push(int val, struct Node **n){
    struct Node *new_node = NULL;
    new_node = createNode(val, new_node);
    new_node->next = *n;
    *n = new_node;
}

void delete(int val, struct Node **n){
    struct Node *curr = *n;
    while(curr->next->data != val){
        curr = curr->next;
    }
    struct Node *del = curr->next;
    curr->next = del->next;
    free(del);
}

void insertLast(int val, struct Node **n){
    struct Node *tmpNode = NULL; 
    struct Node *tmp = *n;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    
    tmpNode = createNode(val, tmpNode);
    tmp->next = tmpNode;
}
 
void insertList(int val, struct Node** n, int pos){
    int i = 1;
    struct Node *tmp = *n;
    struct Node *next = NULL;
    while(i < pos-1 && tmp->next != NULL){
        tmp = tmp->next;
        i = i+1;
    }
    struct Node *ins = NULL;
    ins = createNode(val, ins);
    ins->next = tmp->next;
    tmp->next = ins;
}

int main() 
{ 
    struct Node *node = NULL;
    node = createNode(5, node);
    printList(node);
    printf("\n");
    push(4, &node);
    printList(node);
    printf("\n");
    push(100, &node);
    printList(node);
    printf("\n");
    insertLast(50, &node);
    // insertNode(100, &node);
    // insertNode(100, &node);
    printList(node); 
    // traverse ke setiap node dengan cara mengakses ll->next

    printf("\n");
    // delete(4, &node);
    // insertList(3,&node,2);
    // printList(node); 

    // node = insertNode(4,&node);
    // printf("\n");
    // printList(node); 

    free(node);

    // node = insertNode(1000, node);
    // struct Node* head = NULL; 
    // struct Node* second = NULL; 
    // struct Node* third = NULL; 
  
    // // allocate 3 nodes in the heap 
    // head = (struct Node*)malloc(sizeof(struct Node)); 
    // second = (struct Node*)malloc(sizeof(struct Node)); 
    // third = (struct Node*)malloc(sizeof(struct Node)); 
  
    // head->data = 1; // assign data in first node 
    // head->next = second; // Link first node with second 
  
    // second->data = 2; // assign data to second node 
    // second->next = third; 
  
    // third->data = 3; // assign data to third node 
    // third->next = NULL; 
  
  
    return 0; 
}