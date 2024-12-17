
#include <stdio.h>

int main()
{
    int a,b,c,d;
    scanf("%d%d",&a,&b);
    c=b-a;
    if (c <= 50)
    printf("%d Kwh: %d VND",c,c*1549);
    else if (c <= 100)
    {
		d = 50*1549 + (c-50)* 1600;
    	printf("%d Kwh: %d VND",c,d);
	}
    else if (c <= 200)
    {
    	d = 50*1549 + 50*1600 + (c-100)*1858;
    	printf("%d Kwh: %d VND",c,d);
	}
    else if (c <=300)
    {
		d= 50*1549 + 50*1600 + 100 *1858 + (c-200)*2340;
    	printf("%d Kwh: %d VND",c,d);
	}
    else if (c <=400)
    {
    	d= 50*1549 + 50*1600 + 100 *1858 + 100*2340 + (c-300)*2615;
    	printf("%d Kwh: %d VND",c,d);
	}
    else
    {
    	d=50*1549 + 50*1600 + 100 *1858 + 100*2340 + 100*2615+ (c-400)*2701;
    	printf("%d Kwh: %d VND",c,d);
	}
    return 0;
}
//#include <stdio.h>
//
//int main ()
//{
//    int n;
//    scanf("%d",&n);
//    if (n<10)
//    printf("%d co 1 chu so.",n);
//    else if (n<100)
//    printf("%d co 2 chu so.",n);
//    else if (n<1000)
//    printf("%d co 3 chu so.",n);
//    else if (n<100000)
//    printf("%d co 4 chu so.",n);
//    return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//	double a,b,c,d;
//	scanf("%d%d%d",&a,&b,&c);
//    if ((a > b) && (a>c))
//    {
//		if (b>c)
//			printf("%d %d %d",c,b,a);
//		else
//			printf("%d %d %d",b,c,a);
//		}
//    else if ((b>a) && (b>c))
//    	{
//		if (a>c)
//			printf("%d %d %d",c,a,b);
//		else
//			printf("%d %d %d",a,c,b);
//		}
//    else if ((c>a) && (c>b))
//        {
//		if (a>b)
//			printf("%d %d %d",b,a,c);
//		else
//			printf("%d %d %d",a,b,c);
//		}
//    else if ((a=b)&&(a>c))
// 		printf("%d %d %d",c,a,b);
// 	else if ((a=c)&&(a>b))
// 		printf("%d %d %d",b,a,c);
// 	else if ((c=b)&&(c>a))
// 		printf("%d %d %d",a,b,c);
//	return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//	double a,b,c;
//	scanf("%d%d%d",&a,&b,&c);
//	if ((a>b) && (a>c) && (b>c))
//	{
//	    printf("%d %d %d", c,b,a);
//	}
//	else if ((a>b) && (a>c) && (c>b))
//	{
//	    printf("%d %d %d", b,c,a);
//	}
//	else if ((b>a) && (b>c) && (a>c))
//	{
//	printf("%d %d %d", c,a,b);
//	}
//	else if ((b>a) && (b>c) && (c>a))
//	{
//	    printf("%d %d %d", a,c,b);
//	}
//	else if ((c>a) && (c>b) && (a>b))
//	{
//	    printf("%d %d %d", b,a,c);
//	}
//	else 
//	{
//	    printf("%d %d %d", a,b,c);
//	}
//	return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//	int year,d,m,D;
//	scanf("%d%d%d",&d,&m,&year);
//	if ((year%400==0) || ((year%4==0)&&(year%100!=0)))
//	    D = 29;
//	else 
//	    D = 28;
//	switch (m)
//	{
//	    case 1:
//	    	D = 0;
//	    	break;
//	    case 2:
//	    	D = 31;
//	    	break;
//	    case 3:
//	    	D += 31;
//	    	break;
//	    case 4:
//	    	D += 61;
//	    	break;
//	    case 5:
//	    	D +=92;
//	    	break;
//	    case 6:
//	    	D +=122;
//	    	break;
//	    case 7:
//	    	D += 153;
//	    	break;
//	    case 8:
//	    	D += 184;
//	    	break;
//	    case 9:
//	    	D += 214;
//	    	break;
//	    case 10:
//	    	D +=245;
//	    	break;
//	    case 11:
//	    	D += 276;
//	    	break;
//	    case 12:
//	    	D += 306;
//	    	break;
//	    
//	}
//	printf("%d",D+d);
//	return 0;
//	
//}
