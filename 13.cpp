#include <stdio.h>

long long C( int n, int k){
	if(k == 0 || k == n)
	return 1;
	return C(n,k -1) * ( n-k+1)/k;
}


int main (){
	int i,n;
	scanf("%d",&n);
	for(i = 0; i <= n; i++){
		for(int j = n-i; j > 0; j--){
			printf("   ");
		}
		for(int k = 0; k <= i; k++){
			printf(" %5lld", C(i,k));
		}
		printf("\n");
	}
}
