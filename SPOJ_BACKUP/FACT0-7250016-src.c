#include<stdio.h>
#include<math.h>
typedef long long int ll;
ll a[100],b[100];
int main()
{
	ll n;
	while(scanf("%lld",&n) && n)
	{
		ll s = sqrt(n),i,d=0,j=0;
		while(!(n%2))
		{
			n>>=1;
			d++;
		}
		if(d)
		{
			a[j] = 2;
			b[j++] = d;
		}
		for(i=3;i<=s;i+=2)
		{
			d=0;
			while(!(n%i))
			{
				n/=i;
				d++;
			}
			if(d)
			{
				a[j] = i;
				b[j++] = d;
				if(n==1)
					break;
			}
		}
		if(n!=1)
		{
			a[j] = n;
			b[j++] = 1;
		}
		for(i=0;i<j-1;i++)
			printf("%lld^%lld ",a[i],b[i]);
		printf("%lld^%lld\n",a[i],b[i]);
	}
	return 0;
}
