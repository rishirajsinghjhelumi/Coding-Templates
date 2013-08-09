#include<stdio.h>
#define max 10010
typedef long long int ll;
ll a[max+10],b[max+10],c[max+10];
int main()
{
	ll i,j,x=4;
	a[5] = 6;
	for(i=6;i<=max;i+=2)
	{
		a[i] = a[i-1] + x;
		a[i+1] = a[i] + 2;
		x+=2;
	}
	b[5]=6;
	for(i=6;i<=max;i++)
		b[i] = a[i-1]+b[i-1];
	c[3] = c[4] = 2;
	for(i=5;i<=max;i++)
		c[i] = c[i-1] + b[i];
	ll t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=4;i<=max;i++)
			if(c[i]>=n)
				break;
		printf("%lld\n",i);
	}
	return 0;
}
