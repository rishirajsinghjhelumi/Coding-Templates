#include<stdio.h>
#include<algorithm>
#include<map>
typedef long long int ll;
using namespace std;
pair<ll,ll>a[1000010];
ll input()
{
	register int c = getchar_unlocked();
	ll x=0,neg=1;
	while(c<48 || c>57)
	{
		if(c=='-')
			neg=-1;
		c=getchar_unlocked();
	}
	while(c>=48 && c<=57)
	{   
		x = (x<<3)+(x<<1)+c-48;
		c = getchar_unlocked();
	}   
	return x*neg;
}
int main()
{
	ll t;
	t = input();
	while(t--)
	{
		ll n,i=0,j=0,k,count=0,x;
		n = input();
		a[0].first = 0;
		a[0].second = 0;
		for(i=1;i<=n;i++)
		{
			x = input();
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
