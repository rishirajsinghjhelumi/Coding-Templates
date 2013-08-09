#include<stdio.h>
typedef unsigned long long int ull;
ull mod = 1000000007;
ull fib(ull n) 
{
	ull a=1, b=0, p=0, q=1, prev_a, prev_p = 0;
	while(n>0) 
	{
		if (n%2 == 0) 
		{
			prev_p = p;
			p = (p*p + q*q)%mod;
			q = (2*prev_p*q + q*q)%mod;
			n /= 2;
		}
		else 
		{
			prev_a = a;
			a = (b*q + a*q + a*p)%mod;
			b = (b*p + prev_a*q)%mod;
			n -= 1;
		}
	}
	return b;
}
int main()
{
	ull test_cases;
	scanf("%llu", &test_cases);
	while(test_cases--)
	{
		ull n,m;
		scanf("%llu",&n);
		printf("%llu\n",((fib(2*n)%mod)*(fib(2*n+1)%mod))%mod);
	}
	return 0;

}
