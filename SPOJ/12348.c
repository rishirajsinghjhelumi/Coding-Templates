#include<stdio.h>
#define mod 1000000007
typedef long long int ull;
ull power(ull n ,ull k)
{
	ull ans=1;
	while(k>0)
	{
		if(k&1)
			ans = (ans*n)%mod;
		k>>=1;
		n = (n * n)%mod;
	}
	return ans%mod;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ull n,ans = 0,p,x;
		scanf("%lld",&n);
		p = power(2,n-1);
		while(n--)
		{
			scanf("%lld",&x);
			ans = (ans + x)%mod;
		}
		printf("%lld\n",(ans*p)%mod);
	}
	return 0;
}
