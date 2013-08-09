#include<stdio.h>
#define max 100000
#define mod1 1000000007
#define mod2 1000000006
#define mod3 500000002
#define mod4 148721
#define mod5 41
#define mod6 1681
typedef long long int ull;
ull fact[2*max+10];
ull fact2[2*max+10];
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
ull crt(ull a1,ull a2)
{
	ull x1 = (a1*modinv1)%mod4;
	x1*=2;
	ull x2 = ((a2-x1)*modinv2 + mod6*1000000)%mod6;
	return (x1 + 2*mod4*x2)%mod3;
}
ull pow_fact(ull n)
{
	ull x=0,p=41,s=41;
	while(1)
	{
		ull a = n/s;
		if(!a)
			break;
		x+=a;
		s*=p;
	}
	return x;
}
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
int main()
{
	ull i,x,s,m,m1 = minv(2,mod4),m2=minv(2*mod4,mod6);
	fact[0] = fact2[0] = 1;
	for(i=1;i<=max;i++)
		fact[i] = ( ( ( fact[i-1] * (4*i-2) ) % mod4 ) * minv(i,mod4) ) % mod4;
	for(i=1;i<=2*max;i++)
	{
		x = i;
		while(!(x%41))
			x/=41;
		fact2[i] = (fact2[i-1]*x)%mod6;
	}
	for(i=1;i<=max;i++)
	{
		s = minv(fact2[i],mod6);
		s = (s*s)%mod6;
		x = (fact2[2*i]*s)%mod6;
		m = pow_fact(2*i) - 2*pow_fact(i);
		x = x*power(41,m,mod1);
		printf("%lld\n",crt(fact[i],x%mod6,m1,m2));
	}
	return 0;
}
