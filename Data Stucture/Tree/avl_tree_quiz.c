// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// An AVL tree node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
    char keyword[10];
    long int rightTot;
    long int leftTot;
    int whiteChild;
    int pinkChild;
    int yellowChild;
};

int getTotal(struct Node * curr){
    if(!curr){
        return 0;
    }else{
        int val = getTotal(curr->left) + getTotal(curr->right);
        return curr->key + val;
    }
}

//A utility function to update height
void update(struct Node * curr){
    if(curr->right){
        curr->rightTot = getTotal(curr->right);
    } else {
        curr->rightTot = 0;
    }
    if (curr->left)
    {
        /* code */
        curr->leftTot = getTotal(curr->left);
    }else{
        curr->leftTot = 0;
    }


    if(curr->rightTot > curr->leftTot){
        strcpy(curr->keyword,"pink");
    }else if(curr->rightTot < curr->leftTot){
        strcpy(curr->keyword,"yellow");
    }else{
        strcpy(curr->keyword,"white");
    }
    if(curr->right) update(curr->right);
    if(curr->left) update(curr->left);
}


int getColorCount(struct Node *curr, char color[]){
    if(!curr){
        return 0;
    }
        /* code */
        if(!curr){
            return 0;
        }
        if(strcmp(color,"white") == 0){
            curr->whiteChild = getColorCount(curr->left,color) + getColorCount(curr->right,color);
            if(strcmp(curr->keyword,"white") == 0){
                return curr->whiteChild + 1;
            }else{
                return curr->whiteChild;
            }
        }else if(strcmp(color,"pink") == 0){
            curr->pinkChild = getColorCount(curr->left,color) + getColorCount(curr->right,color);
            if(strcmp(curr->keyword,"pink") == 0){
                return curr->pinkChild + 1;
            }else{
                return curr->pinkChild;
            }
        }else if(strcmp(color,"yellow") == 0){
            curr->yellowChild = getColorCount(curr->left,color) + getColorCount(curr->right,color);
            if(strcmp(curr->keyword,"yellow") == 0){
                return curr->yellowChild + 1;
            }else{
                return curr->yellowChild;
            }
        }
    
} 

void describe(struct Node * curr){
    printf("value: %d\nkeyword: %s\n",curr->key,curr->keyword);
    getColorCount(curr,"white");
    getColorCount(curr,"pink");
    getColorCount(curr,"yellow");
    printf("number of pink child: %d\n",curr->pinkChild);
    printf("number of white child: %d\n",curr->whiteChild);
    printf("number of yellow child: %d\n",curr->yellowChild);
}
//search
void search(struct Node * curr, int x){
    //cek kondisi untuk data tidak ada
    if (curr == NULL) {
        return ;
    }else if (x < curr->key)
    {
        /* code */
        search(curr->left, x);
    }else if (x > curr->key){
        //jika ke x > curr->val, maka ke kanan
        search(curr->right, x);
    }else if(x == curr->key){
        //jika x == curr->val maka return
        describe(curr);
    }  
}


// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get the height of the tree
int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
	NULL left and right pointers. */
struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
    node->leftTot = node->rightTot = 0;
    strcpy(node->keyword,"white");
	node->height = 1; // new node is initially added at leaf
	return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct Node* insert(struct Node* node, int key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d and heigth: %d\n", root->key,root->height);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct Node *root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		printf("%d %s\n", root->key,root->keyword);
		inOrder(root->right);
	}
}

/* Driver program to test above function*/
int main()
{
    int n;
    scanf("%d",&n);
    struct Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        /* code */
        char command[10];
        scanf("%s",command);
        if(strcmp(command,"INSERT") == 0){
            int val;
            scanf("%d",&val);
            root = insert(root, val);
            update(root);
        }else if (strcmp(command,"VIEW") == 0){
            inOrder(root);
            printf("\n");
        }else if (strcmp(command, "DESCRIBE") == 0){
            int val;
            scanf("%d",&val);
            search(root,val);
        }
    }
    

    // /* Constructing tree given in the above figure */
    // root = insert(root, 10);
    // root = insert(root, 20);
    // root = insert(root, 30);
    // root = insert(root, 40);
    // root = insert(root, 50);
    // root = insert(root, 25);

    // /* The constructed AVL Tree would be
    //             30
    //         / \
    //         20 40
    //         / \	 \
    //     10 25 50
    // */

    // printf("Preorder traversal of the constructed AVL"
    //         " tree is \n");
    // inOrder(root);

return 0;
}
