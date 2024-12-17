//#include <stdio.h>
//#include <math.h> 
//int main() {
//	int giay1, giay2, giay3, giaytong,X, Y, Z;
//	// X la gio, Y la phut, Z la giay 
//	scanf("%dh%dm%ds", &X,&Y,&Z);
//	giay1= X*3600;
//	giay2= Y*60;
//	giay3= Z;
//	giaytong= giay1 + giay2 + giay3;
//	printf("Number of seconds: %d", giaytong);
//	return 0;
//		
//}
//#include <stdio.h>
//int main()
//{
//    int a;
//    float c;
//    float pi = 3.14;
//    scanf("%d",&a);
//    c= 2*a*pi;
//    printf("%.2f",c);
//    return(0);
//}
//#include <stdio.h>
//int main()
//{
//    int a;
//    scanf("%d",&a);
//    printf("%d days %02d:%02d:%02d",a/86400,(a%86400)/3600,((a%86400)%3600)/60,(((a%86400)%3600)%60)/1);
//    return(0);
//}
#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%dh%dm%ds",&a,&b,&c);
	printf("Number of seconds: %d",a*3600+b*60+c);
	return(0);
}
