#include<stdio.h>
#define max 350
typedef long long int ll;
ll mod=1234567891;
ll fact[max+10];
ll B[max+10];
ll inv[max+10];
ll inv2[max+10];
ll f[max+10];
ll p[max+10];
ll power(ll n ,ll k)
{
	ll ans=1;
	while(k>0)
	{
		if(k&1)
			ans = (ans*n)%mod;
		k>>=1;
		n = (n * n)%mod;
	}
	return ans%mod;
}
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
	fact[0] = 1,inv[0]=1,inv[2]=0;
	for(i=1;i<=max;i++)
	{
		fact[i] = (fact[i-1]*i)%mod;
		inv[i] = minv(fact[i],mod);
		inv2[i] = minv(i,mod);
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
			x = (x+((((((fact[m] * inv[m-k])%mod * inv[k])%mod) * B[k])%mod) * inv2[m-k+1]))%mod;
		B[m] = (1 - x + mod)%mod;
	}
}
ll summatory(ll m)
{
	ll k=0,ans=0,x,s=inv2[m+1];
	for(k=0;k<=m;k++)
	{
		if(!B[k])
			continue;
		x = ((((fact[m+1] * inv[m+1-k])%mod) * inv[k])%mod * B[k])%mod;
		x = (x*s)%mod;
		ans = (ans + x*p[m+1-k])%mod;
	}
	return ans%mod;
}
int main()
{
	gen_fact_inv();
	gen_bernolli();
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll m,k,x,n,i,ans = 0;
		scanf("%lld%lld",&n,&m);
		ll s = inv2[m+1];
		for(i=0;i<=m+2;i++)
			p[i] = power(n,i);
		for(k=0;k<=m;k++)
		{
			if(!B[k])
				continue;
			x = ((((fact[m+1] * inv[m+1-k])%mod) * inv[k])%mod * B[k])%mod;
			x = (x*s)%mod;
			ans = (ans + x*summatory(m+1-k))%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
