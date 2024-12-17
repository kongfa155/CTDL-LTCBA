#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int *numbers;
	int size;
} NaturalNumberArray;

NaturalNumberArray createArray(int size){
	NaturalNumberArray array;
	array.size = size;
	array.numbers = (int*)malloc(size * sizeof(int));
	return array;
}

void freeArray(NaturalNumberArray *array){
	free(array->numbers);
	array->numbers = NULL;
	array->size = 0;
}

int main(){
	int n,i, l1;
	printf("Nhap chieu dai cua day so: ");
	scanf("%d",&n); 
	printf("\n");
	NaturalNumberArray a = createArray(n);
	printf("Nhap day so 1: ");
	for(i = 0; i < a.size;i++){
		scanf("%d", a->numbers[i]);
		printf("%d ",a->numbers[i]);
	}
	
}
