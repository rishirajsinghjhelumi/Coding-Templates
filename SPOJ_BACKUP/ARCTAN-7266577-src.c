#include<stdio.h>
long long t,a,n,k,b,c;
int main()
{
	for(scanf("%lld",&t);t--&&scanf("%lld",&a);)
	{
		n=a*a+1;
		k=a;
		while(k)
		{
			if(n%k==0)
				break;
			k-=1;
		}
		c=a+k;
		b=(a*c+1)/k;
		printf("%lld\n",b+c);
	}
	return 0;
}
