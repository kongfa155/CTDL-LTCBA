#include <stdio.h>

#define MAXLENGTH 100
#define NULL_NODE -1

typedef int Node;
typedef char LabelType;

typedef struct {
    Node      P[MAXLENGTH];
    LabelType L[MAXLENGTH];
    int maxNode;
} Tree;

void makeNull(Tree *pT){
    pT->maxNode = NULL_NODE;
}

int empty(Tree *pT){
    return (pT->maxNode == NULL_NODE);
}

Node parent(Node n, Tree *pT){
	if( n < 0 || n > pT->maxNode){
		return NULL_NODE;
	}
	
	return pT->P[n];
}

LabelType label(Node n, Tree *pT){
	if( n < 0 || n > pT->maxNode){
		return 'o';
	}
	
	return pT->L[n];
}


Node root(Tree *pT){
	if(pT->maxNode == NULL_NODE){
		return NULL_NODE;
	}
	return 0;
}

Node leftmostChild(Node n, Tree *pT){
	if(n < 0 || n > pT->maxNode){
		return NULL_NODE;
	}
	Node i;
	for(i = n + 1; i <= pT->maxNode; i++){
		if(pT->P[i] == n){
			return i;
		}
	}	
	return NULL_NODE;
}

Node rightSibling(Node n, Tree *pT){
	if(n < 0 || n > pT->maxNode){
		return NULL_NODE;
	}
	Node i;
	for(i = n + 1; i <= pT->maxNode; i++){
		if(pT->P[i] == pT->P[n]){
			return i;
		}
	}	
	return NULL_NODE;
}

void preorder(Node n, Tree *pT){
	if(n == NULL_NODE){
		return;
	}
	printf("%c ", pT->L[n]);
	Node child = leftmostChild(n, pT);
	while(child != NULL_NODE){
		preorder(child, pT);
		child = rightSibling(child, pT);
	}
}

void inorder(Node n, Tree *pT){
	if(n == NULL_NODE){
		return;
	}
	Node child = leftmostChild(n, pT);
	if(child== NULL_NODE){
		printf("%c ", pT->L[n]);
		return;
	}
	
	inorder(child, pT);
	printf("%c ", pT->L[n]);
	child = rightSibling(child, pT);
	while(child != NULL_NODE){
		inorder(child, pT);
		child = rightSibling(child, pT);
	}
}

void postorder(Node n, Tree *pT){
	if(n == NULL_NODE){
		return;
	}
	Node child = leftmostChild(n, pT);
	while(child != NULL_NODE){
		postorder(child, pT);
		child = rightSibling(child, pT);
	}
	printf("%c ", pT->L[n]);
}

int depth(Node n, Tree *pT){
	if(n < 0 || n >pT->maxNode)
		return -1;
	int dep = 0;
	Node child = parent(n, pT);
	while(child != NULL_NODE){
		child = parent(child,pT);
		dep++;
	}
	return dep;
}

int height(Node n, Tree *pT){
    if(n < 0 || n > pT->maxNode)
        return -1;
    Node child = leftmostChild(n, pT);
    int h = -1;
    while(child != NULL_NODE){
        int heightNode = height(child, pT);
        if(h < heightNode){
            h = heightNode;
        }
        child = rightSibling(child,pT);
    }
    return h + 1;
}

int main(){
	Tree T;
    int n;
    scanf("%d", &n);    //read number of node
    T.maxNode = n - 1;  //maxNode = n - 1

    for (int i = 0; i < n; i++) //read label of nodes
        scanf(" %c", &T.L[i]);

    T.P[0] = NULL_NODE;         //parent of root is NULL_NODE
    for (int i = 1; i < n; i++) //read parent of other nodes
        scanf("%d", &T.P[i]);
        
	preorder(0,&T);
	printf("\n");
	inorder(0,&T);
	printf("\n");
	postorder(0,&T);
	printf("\n");
	int u;
	scanf("%d", &u);
	printf("%d\n", height(u,&T));
	printf("%d\n", depth(u,&T));	
}
