#include<stdio.h>
#include<math.h>
typedef long long int ull;
ull len=0;
ull mulmod(ull a,ull b,ull mod)
{
	if(a<1000000000 && b<1000000000)
		return (a*b)%mod;
	ull x = 0,y=a%mod;
	while(b > 0)
	{
		if(b&1)
			x = (x+y)%mod;
		y = (y<<1)%mod;
		b >>=1;
	}
	return x;
}
ull power(ull n ,ull k,ull mod)
{
	ull ans=1;
	while(k>0)
	{
		if(k&1)
			ans = mulmod(ans,n,mod);
		k>>=1;
		n = mulmod(n,n,mod);
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
ull input()
{
	register int c = getchar_unlocked();
	ull x=0;
	len = 0;
	while(c<48 || c>57)
		c=getchar_unlocked();
	while(c>=48 && c<=57)
	{
		len++;
		x = (x<<3)+(x<<1)+c-48;
		c = getchar_unlocked();
	}
	return x;
}
int main()
{
	ull t,n;
	scanf("%lld",&t);
	while(t--)
	{
		n = input();
		ull mod = pow(10,len),e=pow(5,len-1);
		e<<=(len-2>2?len-2:2);
		ull d = minv(3,e);
		printf("%lld\n",power(n,d,mod)%mod);
	}
	return 0;
}
