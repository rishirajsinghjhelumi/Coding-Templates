#include<stdio.h>
typedef long long int ll;
#define max 1000000
#define root 1001
ll tot[max+10];
int main()
{
	ll i,j,k;
	for(i=1;i<=max;i++)
		tot[i]=i;
	for(i=4;i<=max;i+=2)
		tot[i] -= tot[i]>>1;
	for(i=3;i<=max>>1;i+=2)
		if(tot[i] == i)
			for(j=i+i;j<=max;j+=i)
				tot[j] -= tot[j] / i;
	tot[2] = 1;
	for(i=3;i<=max;i+=2)
		if(tot[i] == i)
			tot[i] = i-1;
	for(i=1;i<=1000;i++)
	{
		long double m=1.0,x;
		ll ans;
		for(j=1;j<=i;j++)
		{
			x = (j*1.0)/tot[j];
			if(x>m)
			{
				m = x;
				ans = j;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
