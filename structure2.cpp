#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct ElementType{
	char name[50];
	int mark;	
}ElementType;

typedef struct Student {
    ElementType Student;
    struct Student *next;
} Student;

typedef Student *Position;
typedef Position List;

void printList(List *pL){
    Position temp = *pL;
    while(temp != NULL){
    	printf("%s: %d\n",temp->Student.name,temp->Student.mark);
 	   temp = temp->next;
	}
    printf("---END---");
}

void insert(ElementType x, int p, List *pL)
{
	Position P = *pL;
	for(int i = 1; i < (p-1); i++){
		P = P->next;
	}
    Position temp;
    temp = P->next;
    P->next = (Position)malloc(sizeof(Student));
    P->next->Student.mark = x.mark;
    strcpy(P->next->Student.name,x.name);
	P->next->next= temp;
}


void deleteName( int p, List *pL)
{
	Position P = *pL;
	for(int i = 1; i < (p-1); i++){
		P = P->next;
	}
    Position temp;
    temp = P->next;
    P->next = temp->next;
    free(temp);
}

int locate(char c[], List *pL)
{
    Position temp = *pL;
    while(temp->next != NULL){
        if(strcmp(temp->Student.name,c) == 0)
            return temp->Student.mark;
        temp = temp->next;
    }
}

int main() {
	char name[50];
	scanf("%[^\n]%*c",name);
	Position one = (Position)malloc(sizeof(Student));
	Position two = (Position)malloc(sizeof(Student));
	Position three = (Position)malloc(sizeof(Student));
	Position four= (Position)malloc(sizeof(Student));
	Position five = (Position)malloc(sizeof(Student));
	
//initial
	one->next = NULL;
	two->next = NULL;
	three->next = NULL;
	four->next = NULL;
	five->next = NULL;
//Assign data	
	strcpy(one->Student.name, "Harry Potter");
	one->Student.mark = 10;
	strcpy(two->Student.name, "Hermione Granger");
	two->Student.mark = 8;
	strcpy(three->Student.name, "Draco Malfoy");
	three->Student.mark = 7;
	strcpy(four->Student.name, "Luna Lovegood");
	four->Student.mark = 8;
	strcpy(five->Student.name, "Ron Weasley");
	five->Student.mark = 9;
//Connect list
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
//	five->next = NULL;
	List L = one;
	printList(&L);
	printf("\n");
	ElementType six;
    strcpy(six.name, "Gini Weasley");
    six.mark = 6;
    insert(six,2,&L);
    printList(&L);
    printf("\n");
    deleteName(3,&L);
    printList(&L);
    printf("\n");
    printf("%i",locate(name,&L));
    free(L);
	return 0;
}


