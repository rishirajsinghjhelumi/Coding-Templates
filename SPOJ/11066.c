#include<stdio.h>
#include<math.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		long long int x,y,s,i,n,a,d,c;
		scanf("%lld%lld%lld",&x,&y,&s);
		n = (3.5*x)/(x+y) + (2.5*y)/(x+y) + (s*1.0)/(x+y) + sqrtl(((3.5*x)/(x+y) + (2.5*y)/(x+y) + (s*1.0)/(x+y))*((3.5*x)/(x+y) + (2.5*y)/(x+y) + (s*1.0)/(x+y))-(12.0*s)/(x+y));
		d = (y-x)/(n-6);
		a = x - 2.0*d;
		printf("%lld\n",n);
		for(i=0;i<(n);i++)
			printf("%lld ",a+d*i);
		printf("\n");
	}
	return 0;
}
