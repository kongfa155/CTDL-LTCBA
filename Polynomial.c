#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
		*pT = (Node*)malloc(sizeof(Node));
		(*pT)->label.c = c;
		(*pT)->label.e = e;
		(*pT)->left = (*pT)->right = NULL;
		return;
	}
	else if( (*pT)->label.e > e ){
		insert(c,e,&(*pT)->left);
	}
	else if( (*pT)->label.e < e ){
		insert(c,e,&(*pT)->right);
	}
	else if( (*pT)->label.e == e){
		(*pT)->label.c += c;
	}
	return;
}

int mark = 0;
void printPolynomial(Polynomial *pT){
	if(*pT == NULL || (*pT)->label.e < 0){
		return;
	}
	printPolynomial(&(*pT)->left);
	if(mark == 0){
		printf("(%.2f)x^%d ", (*pT)->label.c, (*pT)->label.e);
		mark++;
	}
	else {
		printf("+ (%.2f)x^%d ", (*pT)->label.c, (*pT)->label.e);
	}
	printPolynomial(&(*pT)->right);
	mark = 0;  
}

double evaluate(double val, Node *p){
	if(p == NULL){
		return 0;
	}
	return p->label.c*pow(val,p->label.e) + evaluate(val,p->left) + evaluate(val, p->right);
}

double coefficient(int e, Polynomial *pT){
	if(*pT == NULL){
		return 0;
	}
	if(e = (*pT)->label.e){
		return (*pT)->label.c;
	}
	else if( (*pT)->label.e < e){
		coefficient(e, &(*pT)->right);
	}
	else if( (*pT)->label.e > e){
		coefficient(e, &(*pT)->left);
	}
}

Polynomial differentiate(Node *P){
	if(P == NULL){
		return NULL;
	}
	Polynomial result = (Node*)malloc(sizeof(Node));
	result->label.c = P->label.c*P->label.e;
	result->label.e = P->label.e - 1;
	result->left = differentiate(P->left);
	result->right = differentiate(P->right);
	return result;
}
int main() {
   Polynomial p = NULL;
    insert(3.0, 2, &p);
    insert(5.0, 1, &p);
    insert(7.0, 0, &p);
    insert(2.0, 3, &p);

    printf("Original polynomial: ");
    printPolynomial(&p);
    printf("\n");
    printf("P(2.00) = %.2f", evaluate(2,p));
    printf("\n");
    printf("C(2.00) = %.2f\n", coefficient(2,&p));
    Polynomial New = differentiate(p);
    printPolynomial(&New);
}
