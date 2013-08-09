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
		c = (3.5*x)/(x+y) + (2.5*y)/(x+y) + (s*1.0)/(x+y);
		if(x<y)
			n = c + sqrtl(c*c-(12.0*s)/(x+y));
		else
			n = c + sqrtl(c*c-(12.0*s)/(x+y));
		d = (y-x)/(n-6);
		a = x - 2.0*d;
		printf("%lld\n",n);
		for(i=0;i<(n-1);i++)
			printf("%lld ",a+d*i);
		printf("%lld\n",a+d*i);
	}
	return 0;
}
