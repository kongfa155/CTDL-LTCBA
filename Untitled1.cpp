#include <stdio.h>

void Move(int n,char A,char B,char C)
{
    if (n==1)
    {
    	printf("%c -> %c\n",A,C);
    }
    else 
    {
    Move(n-1,A,C,B);
    printf("%c -> %c\n",A,C);
    Move(n-1,B,A,C);
	}

}
int main ()
{
Move(3, 'A', 'B', 'C');
} 
