#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXLENGTH 100



//Khai bao stack cho HauTo
typedef struct {
	char elements[MAXLENGTH];
	int top;
} Stack;

//Khai bao cay nhi phan
typedef struct NodeTag{
	char c;
	struct NodeTag *parent;
    struct NodeTag *left;
    struct NodeTag *right;
}Node;

typedef Node* Tree;

//Khai bao Stack cho viec tao cay
typedef struct {
	Node* elements[MAXLENGTH];
	int top;
} StackNode;

//Khai bao map
typedef struct {
	char label;
	int value;
}ElementType;


typedef struct {
	ElementType buckets[MAXLENGTH];
}Map;


//Ham bam
int h(char c){
	return c %26;
}

void makeNullMap(Map *pM){
	int i;
	for( i = 0; i < 26; i++){
		pM->buckets[i].value = 0;
	}
}

//Ham in Map
void printMap(Tree T, Map *pM){
	printf("%d\n",traversalAndCaculate(T, pM));
}
//Ham xai cho Stack thuong
void makeNullStack(Stack *pS){
	pS->top = MAXLENGTH;
}

char top(Stack *pS){
	if(pS->top >= MAXLENGTH) return '0';
	return pS->elements[pS->top];
}

void pop(Stack *pS){
	if(pS->top >= MAXLENGTH) return;
	pS->top++;
}

void push(char x, Stack *pS){
	if(pS->top < 0){
		return ;
	}
	pS->top--;
	pS->elements[pS->top] = x;
}

//Ham do uu tien
int prefer(char c){
	if(c == '+' || c == '-')
		return 1;
	if(c == '*')	return 2;
	return 0;
}

//Ham chuyen tu chuoi sang hau to
char* convertToHauTo(Stack *pS, char input[]){
	//Lay chieu dai chuoi dau vao
	int lengthString = strlen(input);
	//Tao mot chuoi ket qua
	int i, flag = 0, index = 0;
	for(i = 0; i < lengthString;i++){
		if(input[i] == '(' || input[i] == ')') flag++;
	}
	char *output = (char*)malloc(sizeof(char) * (lengthString - flag));


	for(i = 0; i < lengthString ; i++){
		
		char token = input[i];
		//Xet truong hop cua char
		//So -> day thang vao ket qua
		if((token >= 'a' && token <= 'z' ) || ( token >= 'A' && token <= 'Z') || (token >= '0' && token <='9')){
			output[index] = token;
			index++;
		}
		//Khong phai so
		//Neu la dau
		else if( token == '+' || token == '-' || token == '*'){
				while((pS->top != MAXLENGTH) && (prefer(top(pS)) >= prefer(token))){
					output[index] = top(pS);
					index++;
					pop(pS);
			}
				push(token, pS);
			}
		//Neu la dau ngoac
		else if(token == '('){
				push(token, pS);
			}
		else if(token == ')'){
			while(pS->top < MAXLENGTH && top(pS)!='('){
				output[index] = top(pS);
				index++;
				pop(pS);
			}
			pop(pS);
		}
		}
	//Loi tat ca nhung dau con lai trong Stack		
	while(pS->top != MAXLENGTH){
			output[index] = top(pS);
			index++;
			pop(pS);
		}
	return output; 
}

//Ham xai cho StackNode
void makeNullSN(StackNode *pS){
	pS->top = 0;
}

Tree topAndPop(StackNode *pS){
	if(pS->top <= 0){
		return NULL;
	}
	return pS->elements[pS->top--];
}

void pushNS(Node *T,StackNode *pS){
	if(pS->top == MAXLENGTH) return;
	pS->top++;
	pS->elements[pS->top] = T;
}



//Ham tao cay 
Tree create2(char v, Tree T1, Tree T2){
	Tree T = (Node*)malloc(sizeof(Node));
	T->c = v;
	T->left = T1;
	T->right = T2;
	T1->parent = T2->parent = T;
	return T;
}

Tree create0(char c){
	Tree T = (Node*)malloc(sizeof(Node));
	T->c = c;
	T->left = T->right = T->parent = NULL;
	return T;
}

//Chuyen doi tu Hau to sang cay
Tree convertProfixToTree(char input[]){
	StackNode S;
	makeNullSN(&S);
	int i ;
	int lengthS = strlen(input);
	for(i = 0; i < lengthS; i++){
		char token = input[i];
		//Neu la so thi bo vao stack
		if(token != '+' && token != '-' && token != '*'){
			Node *T = create0(token);
			pushNS(T, &S);
		}
		//Neu la dau thi loi 2 thg gan nhat trong Stack ra lam con cua no
		else {
			Node* T2 = topAndPop(&S);
			Node* T1 = topAndPop(&S);
			Node* T = create2(token, T1, T2);
			//Day cay moi tao vao trong Stack
			pushNS(T, &S);
		}
	}
	//Lay ket qua cuoi cung ra khoi Stack
	Tree T = topAndPop(&S);
	return T;
}

//Tra ve gia tri cua x,y,z 
int value(char c,Map *pM){
	int i = h(c);
	return pM->buckets[i].value;
}

//Ham de duyet cay va tinh gia tri
int traversalAndCaculate( Tree T,Map *pM){
	if(T == NULL){
		return 1;
	}
	//Neu cay la ky tu thi tra ve gia tri cua no
	if(T->c >= 'a' && T->c <= 'z'){
		return value(T->c, pM);
	}
	//Tinh 2 ben nhanh xong tuy vao dau ma thuc hien phep toan
	int left = traversalAndCaculate(T->left,pM);
	int right = traversalAndCaculate(T->right,pM);
	if(T->c == '+'){
		return left + right; 
	}
	
	else if (T->c == '-'){
		return left - right; 
	}
	
	else if (T->c == '*'){
		return left * right; 
	}
	//Tra ve gia tri cua chinh nut nay
	else return T->c - '0';
}

//Cap nhat gai tri cua x,y,z neu khong co thi them vao
void update(int v, char c, Map *pM){
	int i = h(c);
	if(pM->buckets[i].label == c){
		pM->buckets[i].value = v;
	}
	pM->buckets[i].label = c;
	pM->buckets[i].value = v;
}


//A+B*(C-D)+E-F
int main () {
    char s[100];
    char cmd[10];
    char x;
    int v;
    scanf("%s", s);
    Stack S;
    makeNullStack(&S);
    char* B = convertToHauTo(&S,s);
    printf("%s\n",B);
    Tree T = convertProfixToTree(B);
    Map M;
    makeNullMap(&M);
	while (1) {
        scanf("%s", cmd);
        if (strcmp("DONE", cmd) == 0)
            return 0;
        
        if (strcmp("PRINT", cmd) == 0) {
            printMap(T,&M);
            
        } else if (strcmp("SET", cmd) == 0) {

            scanf("%d %c", &v, &x);
            update(v,x,&M);
        }
    }
    return 0;
}
