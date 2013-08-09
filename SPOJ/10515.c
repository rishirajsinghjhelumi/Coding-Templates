#include<stdio.h>
#define mod 1000000007
#define max 1000000
typedef long long int ull;
ull a[max+10];
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
	ull i,t,n,x;
	a[1] = 1;
	for(i=2;i<=max;i++)
		x=i-1,a[i] = (((a[i-1]*(4*x+2))%mod)*minv(x,mod))%mod;
	for(scanf("%lld",&t);t--;scanf("%lld",&n),printf("%lld\n",a[n]));
	return 0;
}
