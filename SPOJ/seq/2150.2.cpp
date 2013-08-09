#include<stdio.h>
#include<algorithm>
#include<map>
typedef unsigned long long int ll;
using namespace std;
pair<ll,ll>a[1000010];
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,i=0,j=0,k,count=0,x;
		scanf("%lld",&n);
		a[0].first = 0;
		a[0].second = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			a[i].first = a[i-1].first + x;
			a[i].second = i;
		}
		sort(a,a+n);
		i=0;
		while(j<=n)
		{
			if(a[j].first - a[i].first < 47)
				j++;
			else if(a[j].first - a[i].first > 47)
				i++;
			else
			{
				ll ci=i,cj=j;
				while(a[ci+1].first==a[ci++].first);
				while(a[cj+1].first==a[cj++].first);
				while(i<ci && j<cj)
				{
					if(a[i].second > a[j].second)
						j++;
					else
						count+= cj-j,i++;
				}
				i = ci,j = cj;
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}
