#include<stdio.h>
typedef long long int ll;
ll gcd(ll a ,ll b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
int main()
{
	ll n,i;
	while(scanf("%lld",&n) && n)
	{
		ll g1,g2,g3,i,p=0,g;
		ll a[n],b[n],c[n];
		scanf("%lld%lld%lld",&a[0],&b[0],&c[0]);
		g1 = a[0];
		g2 = b[0];
		g3 = c[0];
		p = a[0]*b[0]*c[0];
		for(i=1;i<n;i++)
		{
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			g1 = gcd(g1,a[i]);
			g2 = gcd(g2,b[i]);
			g3 = gcd(g3,c[i]);
			p += a[i]*b[i]*c[i];
		}
		g = gcd(g1,g2);
		g = gcd(g,g3);
		if(g1==g2 && g2==g3)
			p = p / (g1*g2*g3);
		else
			p = p / (g*g*g);
		printf("%lld\n",p);
	}
	return 0;
}
