#include<stdio.h>
#define mod 10007
#define max 310
typedef long long int ll;
ll fact[max+10];
ll B[max+10];
ll inv[max+10];
ll minv(ll a,ll n)
{
	ll i = n, v = 0, d = 1;
	while (a>0)
	{
		ll t = i/a, x = a;
		a = i % x;
		i = x;
		x = d;
		d = v - t*x;
		v = x;
	}
	return (v+n)%n;
}
void gen_fact_inv()
{
	ll i;
	fact[0] = 1,inv[0]=1;
	for(i=1;i<=max;i++)
	{
		fact[i] = (fact[i-1]*i)%mod;
		inv[i] = minv(fact[i],mod);
	}
}
void gen_bernolli()
{
	B[0] = 1;
	ll i,k,x,m;
	for(m=1;m<=max;m++)
	{
		if(m&1 && m>2)
		{
			B[m] = 0;
			continue;
		}
		x = 0;
		for(k=0;k<m;k++)
			x = (x+((( fact[m] * inv[m-k] * inv[k])%mod) * B[k] * minv(m-k+1,mod)))%mod;
		B[m] = (1 - x + max*mod)%mod;
	}
}
int main()
{
	gen_fact_inv();
	gen_bernolli();
	ll m,k,x;
	scanf("%lld",&m);
	ll s = minv(m+1,mod);
	for(k=0;k<=m;k++)
	{
		x = ((fact[m+1] * inv[m+1-k] * inv[k])%mod * B[k])%mod;
		printf("%lldx^%lld + ",(x*s)%mod,m+1-k);
	}
	printf("0x^0\n");
	return 0;
}
