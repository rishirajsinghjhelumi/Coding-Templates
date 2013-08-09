#include<stdio.h>
#include<algorithm>
#include<assert.h>
typedef long long int ll;
using namespace std;
ll gcd(ll a,ll b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
ll input()
{
	register int c = getchar_unlocked();
	ll x=0;
	while(c<48 || c>57)
		c=getchar_unlocked();
	while(c>=48 && c<=57)
	{
		x = (x<<3)+(x<<1)+c-48;
		c = getchar_unlocked();
	}
	return x;
}
int main()
{
	int test_cases;
	ll b = 1000000000;
	b*=b;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		char s1[100],s2[100];
		ll n,g1=0,x,i,d=0;
		scanf("%s%s%lld",s1,s2,&n);
		ll a[n];
		for(i=0;i<n;i++)
			a[i] = input();
		sort(a,a+n);
		i=0;
		if(n!=1)
		{
			while(1)
			{
				x = a[i+1] - a[i];
				if(x)
				{
					g1 = x;
					i++;
					d = 1;
					break;
				}
				if(++i==n-1)
					break;
			}
			for(;i<n-1;i++)
			{
				x = a[i+1] - a[i];
				if(x)
					g1 = gcd(g1,x);
			}
		}
		if(g1<=b && d==1)
			printf("%s %s %lld\n",s1,s2,g1);
		else
			printf("%s %s I can't count that high\n",s1,s2);
	}
	return 0;
}
