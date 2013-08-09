#include<stdio.h>
#define max 1500010
typedef long long int ll;
ll a[max];
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ll n,m,s,t,i;
		scanf("%lld%lld%lld%lld",&s,&t,&n,&m);
		for(i=1;i<=n;i++)
		{
			s = (78901 + 31*s)%699037;
			t = (23456 + 64*t)%2097151;
			a[i] = (s%100 + 1)*(t%100 + 1);
		}
		ll j=1,k,l=1,sum=0,x,count=0,min=n;
		for(i=1;i<=n;i++)
		{
			sum += a[i];
			if(sum>=m)
			{
				x=i-l;
				if(x<min && sum==m)
					min = x+1;
				else if(x<min && sum>m)
					min = x;
				while(sum>=m)
				{
					sum -= a[l++];
					x=i-l;
					if(x<min && sum>m)
						min = x;
					else if(i-l<min && sum==m)
						min = x+1;
				}
			}
		}
		printf("%llu\n",min);
	}
	return 0;
}
