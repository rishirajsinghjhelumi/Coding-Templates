#include<stdio.h>
#include<assert.h>
#define max 100000
typedef long long int ull;
ull ncr[max+10];
ull power(ull n ,ull k,ull mod)
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
ull minv(ull a, ull n) 
{
	ull i = n, v = 0, d = 1;
	while (a>0) 
	{
		ull t = i/a, x = a;
		a = i % x;
		i = x;
		x = d;
		d = v - t*x;
		v = x;
	}
	return (v+n)%n;
}
int main()
{
	ull i,mod = 1000000007,mod2=mod-1,mm=mod2>>1;
	ncr[0] = 1;
	for(i=1;i<=max;i++)
		ncr[i] = (((((i<<2)-2)*ncr[i-1])%mod2)*minv(i,mm))%mod2;
	ull a,b,n,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&n);
		printf("%lld\n",power(a,power(ncr[n],b,mod2),mod));
	}
	return 0;
}
