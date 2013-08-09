#include<stdio.h>
#include<assert.h>
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
#define modinv1 minv(2,mod4)
#define modinv2 minv(2*mod4,mod6)
ull crt(ull a1,ull a2)
{
	ull x1 = (a1*modinv1)%mod4,ss=1681;
	x1*=2;
	ull x2 = ((a2-x1)*modinv2 + ss*10000000)%mod6;
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
	if(k==0)
		return ans;
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
	ull i,x,s,m;
	ull f41[10];
	f41[0] = 1;
	for(i=1;i<=9;i++)
		f41[i] = f41[i-1]*41;
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ull a,b,n;
		scanf("%lld%lld%lld",&a,&b,&n);
		s = minv(fact2[n],mod6);
		s = (s*s)%mod6;
		x = (fact2[2*n]*s)%mod6;
		m = pow_fact(2*n) - 2*pow_fact(n);
		x = x*f41[m];
		ull y = crt(fact[n],x%mod6);
		if(y==0)
			y = mod3;
		if(n==0)
			y = 1;
		ull y1 = power(b,y,mod2);
		if(b==0)
			y1 = 0;
		ull z = power(a,y1,mod1);
		printf("%lld\n",z);
	}
	return 0;
}
