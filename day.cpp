#include <stdio.h>

int main()
{
	int n,n1,n2;
	scanf("%d",&n);
	for (int i =0; i <250 ; i++)
	{
	n=n1;
	n1=n2;
	n2=n1+n;
	printf("%d ",n1);	
	} 
	return (0);
} 
