#include<stdio.h>
typedef long long int ull;
ull power(ull n ,ull k,ull mod)
{
	ull temp = 1,ans=1;
	while(k>0)
	{
		if(k&temp)
		{
			ans = (ans*n)%mod;
			k-=temp;
		}
		temp <<=1;
		n = (n * n)%mod;
	}
	return ans%mod;
}
ull mod_inv(a,mod)
{
	ull b = mod;
	ull x=0,y=1,u=1,v=0,m,n,q,r;	
	while(a>0)
	{
		q = b/a;
		r = b%a;
		m = x - u*q;
		n = y - v*q;
		b = a;
		a = r;
		x = u;
		y = v;
		u = m;
		v = n;
	}
	return (x+mod)%mod;
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
	v %= n;
	if (v<0) v = (v+n)%n;
	return v;
}
int main()
{
	ull t;
	scanf("%lld",&t);
	while(t--)
	{
		ull a,d,r,n,mod,p,ans;
		scanf("%lld%lld%lld%lld%lld",&a,&d,&r,&n,&mod);
		if(n&1)
		{
			n++;
			p = power(r,n/2-1,mod);
			ans = (a*p + (((d*((p*r-1+mod)%mod))%mod)*minv(r-1,mod))%mod - d + n*mod)%mod;
		}
		else
		{
			p = power(r,n/2-1,mod);
			ans = (a*p + (((d*((p*r-1+mod)%mod))%mod)*minv(r-1,mod))%mod + n*mod)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
