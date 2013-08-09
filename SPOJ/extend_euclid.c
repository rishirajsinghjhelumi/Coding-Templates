#include<stdio.h>
typedef long long int ull;
ull p1,p2;
ull extended_gcd(ull a,ull b)
{
	ull x=0,y=1,lastx=1,lasty=0;
	while(b)
	{
		ull q = a/b;
		a = b;
		b = a%b;
		x = lastx - q*x;
		lastx = x;
		y = lasty - q*y;
		lasty = y;
	}
	p1 = lastx;
	p2 = lasty;
}
int main()
{
	ull a,b;
	scanf("%lld%lld",&a,&b);
	extended_gcd(a,b);
	printf("%lld %lld\n",p1,p2);
	return 0;
}
