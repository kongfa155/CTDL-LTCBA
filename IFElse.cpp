#include <stdio.h>
#include <math.h>

int main()
{
    double a,b,c,delta,x1,x2;
    scanf("%d%d%d",&a,&b,&c);
    delta = b*b - 4*a*c;
    x1 = (-b-sqrt(delta))/2*a;
    x2 = (-b+sqrt(delta))/2*a;
    if (delta > 0)
    {
        printf("x1 = %.2d\n",x1);
        printf("x2 = %.2d",x2);
    }
    else if (delta==0)
    printf("x = %.2d",-b/2*a);
    else
    printf("No real roots");
    return 0;
}

//#include <stdio.h>
//
//int main ()
//{
//	int  a,b,c,d;
//	scanf("%d%d%d",&a,&b,&c);
//	if ((a>=b) && (a>c))
//	d = a;
//	else if ((b>=c)&&(b>a))
//	d = b;
//	else
//	d = c;
//	printf("%d",d);
//	return 0;
// } 

//#include <stdio.h>
//
//int main ()
//{
//	char c;
//	scanf("%c",&c);
//    switch (c) {
//    case 65:
//    case 69:
//    case 73:
//    case 79:
//    case 85:
//    case 65+32:
//    case 69+32:
//    case 73+32:
//    case 79+32:
//    case 85+32:
//    printf("%c is a vowel.",c);
//    break;
//    default:
//    printf("%c is a consonant.",c);
//    break;
//}
//	return 0;
// } 

//#include <stdio.h>
//
//int main ()
//{
//	int n;
//	scanf("%d",&n);
//	if (n%2==0)
//	printf("%d is even",n);
//	else
//	printf("%d is odd",n);
//	return 0;
// } 

//#include <stdio.h>
//
//int main ()
//{
//	int s,d,m,h;
//	scanf("%d",&s);
//	d = s / 86400;
//	h = (s % 86400)/3600;
//	m = ((s % 86400) % 3600)/60;
//	if (s >=86400)
//	printf("%d days %02d:%02d:%02d",d,h,m,((s % 86400) % 3600)%60);
//	else
//	printf("%02d:%02d:%02d",h,m,((s % 86400) % 3600)%60);
//	return 0;
// } 
