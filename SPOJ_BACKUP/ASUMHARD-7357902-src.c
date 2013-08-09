#include<stdio.h>
#define max 330
typedef long long int ll;
ll mod=1234567891;
ll fact[max+10];
ll B[max+10];
ll inv[max+10];
ll inv2[max+10];
ll f[max+10][max+10];
ll f1[max+10][max+10];
ll input()
{
	register int c = getchar_unlocked();
	ll x=0;
	while(c<48 || c>57)
		c=getchar_unlocked();
	while(c>=48 && c<=57)
	{
		x = (x<<3)+(x<<1)+c-48;
		c = getchar_unlocked();
	}
	return x;
}
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
void summ()
{
	ll m;
	for(m=0;m<=325;m++)
	{
		ll k=0,x,s=inv2[m+1];
		for(k=0;k<=m;k++)
		{
			if(!B[k])
			{
				f1[m][m+1-k] +=0;
				continue;
			}
			x = ((((fact[m+1] * inv[m+1-k])%mod) * inv[k])%mod * B[k])%mod;
			f1[m][m+1-k] = (x*s)%mod;
		}
	}
}
void summatory(ll m,ll i,ll xx)
{
	ll k=0,x;
	for(k=0;k<=m;k++)
		f[i][m+1-k] = (f[i][m+1-k] + (f1[m][m+1-k]*xx)%mod )%mod;
}
void gen_power()
{
	ll k,m,x;
	for(m=0;m<=325;m++)
	{
		ll s = inv2[m+1];
		for(k=0;k<=m;k++)
		{
			if(!B[k])
			{
				f[m][m+1-k] += 0;
				continue;
			}
			x = ((((fact[m+1] * inv[m+1-k])%mod) * inv[k])%mod * B[k])%mod;
			x = (x*s)%mod;
			summatory(m+1-k,m,x);
		}
	}
}
int main()
{
	gen_fact_inv();
	gen_bernolli();
	summ();
	gen_power();
	ll t=input();
	while(t--)
	{
		ll m,k,x,n,i,ans = 0;
		n=input();
		m=input();
		ll p=1;
		for(i=0;i<=m+2;i++)
		{
			if(f[m][i])
				ans = (ans + f[m][i]*p)%mod;
			p = (p*n)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
