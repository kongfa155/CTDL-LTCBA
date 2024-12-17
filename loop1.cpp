//#include <stdio.h>
//int main() {
//    long long a, b, r, A, B;
//    scanf("%lld%lld", &a, &b);
//    A = a; B = b;
//    while (b != 0) {
//        r = a%b;
//        a = b;
//        b = r;
//    }
//    
//    long long LCM = A/a*B;
//    if (LCM < 0) LCM = -LCM;
//
//    printf("%lld\n", LCM);
//        
//   return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int a,i;
//    i = 2;
//    scanf("%d",&a);
//    while(a!=1)
//    {
//        while(i<=a)
//        if (a%i==0)
//        {
//            printf("%d ",i);
//            a = a/i;
//        }
//        else
//        i++;
//    }
////    return 0;
////}
//
//#include <stdio.h> 
//#include <math.h>
//
//int main()
//{
//   	long long a,b,be,lon,e,f;
//    scanf("%lld%lld",&a,&b);
//    if (a<0)
//    a = -a;
//    if (b <0)
//    b = -b;
//    if(a==0 || b ==0)
//    printf("0");
//    if(b>a){
//    be = a;
//    lon = b;
//}
//    if (a >b){
//    lon = a;
//    be = b;
//}
//	while(be!=0)
//	{
//		f = lon%be ;
//		lon=be ;
//		be=f ;
//	}
//	e = a*b/lon;
//    printf("%lld",e);
//    return 0;
//}

//#include <stdio.h>
//
//int main ()
//{
//    double a;
//    double b=0;
//    int i = 1;
//    scanf("%d",&a);
//    while(b<a)
//    {
//    b = b + 1.0/i;
//    i++;
//    }
//    printf("%d",i);
//    return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    int n;
//	int k = 1;
//    scanf("%d",&n);
//    for(int i =0;i<n;i++)
//    {
//		while(k<n)
//		{
//		k=k*2;
//		i++;
//		}
//        printf("%d",i);
//        break;
//    }
//}

//#include <stdio.h>
//
//int main()
//{
//    int n,i;
//    float a;
//    i = 0;
//    float b= -1;
//    float d = 0;
//    float e = 10;
//    scanf("%d",&n);
//	while(i<n){
//	scanf("%f",&a);
//	d = d + a;
//	if (e>a)
//	e = a;
//	if(a>b)
//	b = a;
//	i++;
//	}
//	printf("%.2f %.2f %.2f",d,b,e);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int n,i;
//    float a;
//    i = 0;
//    float b=0;
//    scanf("%d",&n);
//	while(i<n)
//	{
//	scanf("%f",&a);
//	b+= a;
//	i++;
//	}
//	printf("%.2f %.2f",b,b/n);
//    return 0;
//}
//#include <stdio.h>
//
//int main ()
//{
//    float a;
//    int c;
//    scanf("%f%d",&a,&c);
//    for(int i =1; i <=c;i++)
//    a*=a;
//    printf("%2.f",a);
//    return 0;
//}

//#include <stdio.h>
//
//int main ()
//{
//    int a;
//    int b=0;
//    scanf("%d",&a);
//    for(int i =1; i <=a;i=i+2)
//	b = b + -i;
//	for(int c =0; c <=a;c=c+2)
//	b = b + c;
//	printf("%d",b);
//    return 0;
//}


//#include <stdio.h>
//
//int main ()
//{
//    int a,b,p,c;
//    c = 0;
//    scanf("%d%d%d",&a,&b,&p);
//    for(int i = a; i <= b;i++)
//    {
//        if(p%i==0)
//        c++;
//
//    }
//    if(c!=0)   
//	printf("Co it nhat 1 so trong doan [%d, %d] la uoc cua %d.",a,b,p);
//    else
//    printf("Khong co so nao trong doan [%d, %d] la uoc cua %d.",a,b,p);
//    return 0;
//}


//#include <stdio.h>
//
//int main ()
//{
//    int a;
//    int b=0;
//    scanf("%d",&a);
//    for(int i =0; i <=a;i += 2)
//    {
//        printf("%d\n",i);
//    }
//    return 0;
//}


//#include <stdio.h>
//
//int main ()
//{
//    int a;
//    long long b=0;
//    scanf("%d",&a);
//    for(int i =1; i <=a;i++)
//    b = b + i*i;
//    printf("%lld",b);
//    return 0;
//}

//#include <stdio.h>
//
//int main ()
//{
//    int a;
//    float b = 0.0;
//    scanf("%d",&a);
//    for(float i =1; i <=a;i++)
//    b = b + i/(i+1);
//    printf("%.2f",b);
//    return 0;
//}

//#include <stdio.h>
//
//int main ()
//{
//    int a,b;
//    b =0;
//    scanf("%d",&a);
//    while(a>9)
//    {
//        a = a/10;
//        b++;
//    }
//    printf("%d",b+1);
//    return 0;
//}

//#include <stdio.h>
//
//int main ()
//{
//    int a,b,c;
//    b = 0;
//    scanf("%d",&a);
//    while(a>0)
//    {
//    c = a%10;
//    b = b*10 +c;
//	a = a/10;
//    }
//    printf("%d",b);
//    return 0;
//}

//#include <stdio.h>
//
//int main ()
//{
//    int a,b;
//    b =0;
//    scanf("%d",&a);
//    while(a>9)
//    {
//        a = a/10;
//        b++;
//    }
//    printf("Number of digits: %d",b+1);
//    return 0;
//}

//#include <stdio.h>
//
//int main ()
//{
//    int a,b,c,d,e;
//    scanf("%d%d",&a,&b);
//	if(b==0)
//	printf("%d",a);
//	else if(a==0)
//	printf("%d",b);
//	else{
//	if(a<0)
//	a = -a;
//	if(b<0)
//	b = -b;
//	if (a>b)
//	{
//    d = a;
//    e = b;
//	}
//    else{
//    d = b;
//    e = a;
//	}
//	while(d%e!=0)
//	{
//    c =d%e;
//    d = e;
//    e = c;
//	}
//    printf("%d",e);
//}
//    return 0;
//}	
//
//#include <stdio.h>
//
//int main ()
//{
//    int a,b,c,d;
//    scanf("%d%d",&a,&b);
//    if(a<0)
//    a = -a;
//    if (b<0)
//    b = -b;
//	if(a==b)
//	printf("%d",a);
//	else if(a>b)
//	{
//		for( int i = 1; i <= a; i++)
//		if ((a%i==0)&&(b%i==0))
//		c = i;
//		printf("%d",c);
//	}
//	else
//	{
//		for( int i = 1; i <= b; i++)
//		if ((a%i==0)&&(b%i==0))
//		c = i;
//		printf("%d",c);
//	}
//    return 0;
//}
