#include <stdio.h>

int main(void)
{
	int skt;
	printf("So ki tu ban muon nhap vao ");
	scanf("%d",&skt);
	char string[skt];
	int i = 0;
	while(i <= skt+1)
	{
		scanf("%c",&string[i]);
		printf("%c",string[i]);
		i++;
	}
	return 0;
}
