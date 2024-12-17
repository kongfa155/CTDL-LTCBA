#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL_NODE NULL
#define MAXLENGTH 50
typedef char LabelType;

typedef struct NodeTag {
    struct NodeTag *parent;
    struct NodeTag *left;
    struct NodeTag *right;
    LabelType label;
} Node;

typedef Node *Tree; 


typedef struct{
	LabelType elements[MAXLENGTH];
	int top;
} Stack;

void makeNull(Tree *pT){
	(*pT) = NULL;
}

void pop(Stack *pS){
    if(pS->top == MAXLENGTH ){
        printf("Error: stack is empty.\n");
        return;
    }
    pS->top++;
}

ElementType top(Stack *pS){
    if(pS->top == MAXLENGTH){
        return -94.09;
    }
    return pS->elements[pS->top];
}

void push(ElementType x, Stack *pS){
    if(pS->top == 0){
        printf("Error: stack is full\n");
        return;
    }
    pS->top--;
    pS->elements[pS->top] = x;
}


Tree create2(LabelType v, Tree T1,Tree T2){
	Node *T = (Node*)malloc(sizeof(Node));
	T->label = v;
	T->left = T1;
	T->right = T2;
	T->parent = NULL;
	if(T1 != NULL){
		T1->parent = T;
	}
	if(T2 != NULL){
		T2->parent = T;
	}	
	return T;
}

int douutien(char c){
	if(c == '+' || c == '-'){
		return 1;
	}
	if(c == '*'){
		return 2;
	}
	return 3;
}


void inorder(Node *n){
	if(n == NULL){
		return;
	}
	if(douutien(n->left->label) == 1){
		printf("(");
		inorder(n->left);
		printf(")");
	}
	else {
		printf("%c", n->left->label);
	}
	printf("%c", n->label);
	if(douutien(n->right->label) == 1){
		printf("(");
		inorder(n->right);
		printf(")");
	}
	else {
		printf("%c", n->right->label);
	}
}

char* htop(char A[], Stack *pS){
}

Node* copyTree(Node* T){
	if (T == NULL) return NULL;
	return create2(T->label, T->left, T->right);
}

void copyTree2(Tree *T1, Tree *T2){
	if((*T1) == NULL) return ;
	(*T2) = create2((*T1)->label, (*T1)->left, (*T1)->right);
}

void commute(Node *n){
	Node *temp = n->left;
	n->left = n->right;
	n->right = temp;
} 
void preorder(Tree n) {
    if (n == NULL_NODE) {
        return;
    }
    printf("%c ", n->label); 
    preorder(n->left);      
    preorder(n->right);      
}


int main () {
	char c[50];
	Node *A = create2('A', NULL, NULL);
	Node *B = create2('B',NULL,NULL);
	Node *C = create2('C',NULL,NULL);
	Node *Plus = create2('+',B,C);
	Node *Mul = create2('*', A, Plus);
	inorder(Mul);
	printf("\n");
	Node *Mul2 = (Node*)malloc(sizeof(Node));
	copyTree2(&Mul, &Mul2); 
	inorder(Mul2);
}
