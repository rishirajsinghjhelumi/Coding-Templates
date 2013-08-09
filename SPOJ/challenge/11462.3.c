#include<stdio.h>
typedef unsigned long long int ull;
ull fib(ull n,ull mod)
{
	ull a=1, b=0, p=0, q=1, prev_a, prev_p = 0;
	while(n>0) 
	{
		if (!(n%2)) 
		{
			prev_p = p;
			p = (p*p + q*q)%mod;
			q = (2*prev_p*q + q*q)%mod;
			n >>= 1;
		}
		else 
		{
			prev_a = a;
			a = (b*q + a*q + a*p)%mod;
			b = (b*p + prev_a*q)%mod;
			n--;
		}
	}
	return b;
}
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ull a,b,n,mod,ans,i,sum=0;
		scanf("%llu%llu%llu%llu",&a,&b,&n,&mod);
		ans = (a*fib(n,mod)%mod + b*fib(n+1,mod)%mod-b+n*mod)%mod;
		printf("%llu\n",ans);
	}
	return 0;
}
