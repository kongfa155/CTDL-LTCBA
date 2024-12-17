#include <stdio.h>
#include <stdlib.h>

#define NULL_NODE NULL

typedef int LabelType;

typedef struct NodeTag {
    struct NodeTag *left;
    struct NodeTag *right;
    LabelType label;
} Node;

typedef Node *Tree; 

int height(Node *n){
	if(n == NULL) return -1;
	if(n->left == NULL && n->right == NULL){
		return 0;
	}
	else return 1 + (height(n->left) > height(n->right) ? height(n->left) : height(n->right));
}
void preorder(Node *n) {
    if(n == NULL) return;
    printf("%d ",n->label);
    preorder(n->left);
    preorder(n->right);
}

Node* leftRotate(Node *n){
	Node *b = n->right; 
	Node *a = b->left;
	b->left = n;
	n->right = a;
	return b;
}

Node* rightRotate(Node *n){
	Node *b = n->left;
	Node *a = b->right;
	b->right = n;
	n->left = a;
	return b;
}

Node* leftRightRotate(Node *n){
	n->left = leftRotate(n->left);
	return rightRotate(n);
}
Node* newNode(LabelType label) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->label = label;
	node->left = NULL; 
	node->right = NULL; 
	// New node is initially added at leaf 
	return(node);
}
Node* rightLeftRotate(Node *n){
	n->right = rightRotate(n->right);
	return leftRotate(n);
}
int getBalance(Node *n) { 
	if (n == NULL) {
 		return 0; 
 	}
  	return height(n->left) - height(n->right);
}
Node* insert(LabelType x, Node *node) { 
	// Standard BST insertion 
	if (node == NULL) { 
		return newNode(x); 
	} if (x < node->label) {
	 	node->left = insert(x, node->left); 
	} else if (x > node->label) { 
	 	node->right = insert(x, node->right); 
	} else { 
	// Equal keys are not allowed in BST 
		return node; 
	}
	// Update height of this ancestor node 
//	node->height = 1 + max(height(node->left), height(node->right));
	// Get the balance factor of this ancestor node to check whether this node became unbalanced 
	int balance = getBalance(node);
	// If this node becomes unbalanced, then there are 4 cases 
	// Left Left Case 
	if (balance > 1 && x < node->left->label) {
	 	return rightRotate(node);
	} 
	// Right Right Case 
	if (balance < -1 && x > node->right->label) {
	 	return leftRotate(node); 
	} 
	// Left Right Case 
	if (balance > 1 && x > node->left->label) { 
		node->left = leftRotate(node->left);
		return rightRotate(node);
	} 
	// Right Left Case 
	if (balance < -1 && x < node->right->label) {
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	}
	// Return the (unchanged) node pointer 
	return node; 
} 
int main(){
	Tree root = NULL;
	root = insert(10, root);
	root = insert(20, root); 
	root = insert(30, root);
	root = insert(40, root); 
	root = insert(50, root); 
	root = insert(25, root);
	preorder(root);
}


#include <stdio.h>
#include <stdlib.h>

typedef int LabelType;

typedef struct NodeTag {
    LabelType label;
    struct NodeTag *left;
    struct NodeTag *right;
    int height;
} Node;

typedef Node *Tree;

int height(Node *n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(LabelType label) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->label = label;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *n) {
    if (n == NULL) {
        return 0;
    }
    return height(n->left) - height(n->right);
}

Node* deleteMin(Node *node) {
    if (node->left == NULL) {
        return node->right;
    }
    node->left = deleteMin(node->left);
    node->height = max(height(node->left), height(node->right)) + 1;
    return node;
}

Node* findMin(Node *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node *root, LabelType x) {
    if (root == NULL) {
        return root;
    }

    if (x < root->label) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->label) {
        root->right = deleteNode(root->right, x);
    } else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            Node *temp = findMin(root->right);
            root->label = temp->label;
            root->right = deleteNode(root->right, temp->label);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->label);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Tree root = NULL;

    root = insert(9, root);
    root = insert(5, root);
    root = insert(10, root);
    root = insert(0, root);
    root = insert(6, root);
    root = insert(11, root);
    root = insert(-1, root);
    root = insert(1, root);
    root = insert(2, root);

    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);

    root = deleteNode(root, 10);

    printf("\nPreorder traversal after deletion of 10 \n");
    preOrder(root);

    return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int LabelType;
//
//typedef struct NodeTag {
//    LabelType label;
//    struct NodeTag *left;
//    struct NodeTag *right;
//    int height;
//} Node;
//
//typedef Node *Tree;
//
//int height(Node *n) {
//    if (n == NULL) {
//        return 0;
//    }
//    return n->height;
//}
//
//int max(int a, int b) {
//    return (a > b) ? a : b;
//}
//
//Node* newNode(LabelType label) {
//    Node* node = (Node*)malloc(sizeof(Node));
//    node->label = label;
//    node->left = NULL;
//    node->right = NULL;
//    node->height = 1;  // New node is initially added at leaf
//    return(node);
//}
//
//Node* rightRotate(Node *y) {
//    Node *x = y->left;
//    Node *T2 = x->right;
//
//    // Perform rotation
//    x->right = y;
//    y->left = T2;
//
//    // Update heights
//    y->height = max(height(y->left), height(y->right)) + 1;
//    x->height = max(height(x->left), height(x->right)) + 1;
//
//    // Return new root
//    return x;
//}
//
//Node* leftRotate(Node *x) {
//    Node *y = x->right;
//    Node *T2 = y->left;
//
//    // Perform rotation
//    y->left = x;
//    x->right = T2;
//
//    // Update heights
//    x->height = max(height(x->left), height(x->right)) + 1;
//    y->height = max(height(y->left), height(y->right)) + 1;
//
//    // Return new root
//    return y;
//}
//
//int getBalance(Node *n) {
//    if (n == NULL) {
//        return 0;
//    }
//    return height(n->left) - height(n->right);
//}
//
//Node* insert(LabelType x, Node *node) {
//    // Standard BST insertion
//    if (node == NULL) {
//        return newNode(x);
//    }
//    if (x < node->label) {
//        node->left = insert(x, node->left);
//    } else if (x > node->label) {
//        node->right = insert(x, node->right);
//    } else {
//        // Equal keys are not allowed in BST
//        return node;
//    }
//
//    // Update height of this ancestor node
//    node->height = 1 + max(height(node->left), height(node->right));
//
//    // Get the balance factor of this ancestor node to check whether this node became unbalanced
//    int balance = getBalance(node);
//
//    // If this node becomes unbalanced, then there are 4 cases
//
//    // Left Left Case
//    if (balance > 1 && x < node->left->label) {
//        return rightRotate(node);
//    }
//
//    // Right Right Case
//    if (balance < -1 && x > node->right->label) {
//        return leftRotate(node);
//    }
//
//    // Left Right Case
//    if (balance > 1 && x > node->left->label) {
//        node->left = leftRotate(node->left);
//        return rightRotate(node);
//    }
//
//    // Right Left Case
//    if (balance < -1 && x < node->right->label) {
//        node->right = rightRotate(node->right);
//        return leftRotate(node);
//    }
//
//    // Return the (unchanged) node pointer
//    return node;
//}
//
//void preOrder(Node *root) {
//    if (root != NULL) {
//        printf("%d ", root->label);
//        preOrder(root->left);
//        preOrder(root->right);
//    }
//}
//
//int main() {
//    Tree root = NULL;
//
//    root = insert(10, root);
//    root = insert(20, root);
//    root = insert(30, root);
//    root = insert(40, root);
//    root = insert(50, root);
//    root = insert(25, root);
//
//    printf("Preorder traversal of the constructed AVL tree is \n");
//    preOrder(root);
//
//    return 0;
//}

