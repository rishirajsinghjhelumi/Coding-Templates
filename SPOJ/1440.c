#include<stdio.h>
long long t,a,n,k,b,c;
int main()
{
	for(scanf("%lld",&t);t--&&scanf("%lld",&a);)
	{
		for(n=a*a+1,k=a;k&&n%k;k--);
		c=a+k;
		b=(a*c+1)/k;
		printf("%lld\n",b+c);
	}
	return 0;
}
