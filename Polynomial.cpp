#include <stdio.h>
#include <stdlib.h>
#inlcude <math.h>

typedef struct {
	double c;
	int e;
} LabelType;

typedef struct NodeTag {
	LabelType label;
	struct NodeTag *left, *right;
} Node;

typedef Node *Polynomial;

void insert(double c, int e, Polynomial *pT){
	if(*pT == NULL){
		Node *newNode = (Node*)malloc(sizeof(Node));
		newNode->label.c = c;
		newNode->label.e = e;
		newNode->left = newNode->right = NULL;
		return;
	}
	else if( (*pT)->label.e < e ){
		insert(c,e,(*pT)->left);
	}
	else if( (*pT)->label.e == e){
		(*pT)->label.c += c;
	}
	return;
}

void printPolynomial(Polynomial *pT){
	if(*pT==NULL){
		return;
	}
	printPolynomial(&(*pT)->left);
	if(first==1){
		printf("(%.2lf)x^%d", (*pT)->label.c, (*pT)->label.e);
		first++;
	} else {
		printf(" + (%.2lf)x^%d", (*pT)->label.c, (*pT)->label.e);
	}
	printPolynomial(&(*pT)->right);
	
}


int main() {
   Polynomial p = NULL;
    insert(3.0, 2, &p);
    insert(5.0, 1, &p);
    insert(7.0, 0, &p);
    insert(2.0, 3, &p);

    printf("Original polynomial: ");
    printPolynomial(&p);
}
