#include<stdio.h>
#define max 100000
typedef long long int ll;
ll a[max+10];
ll ans[max+10];
ll input()
{
	register char c = getchar_unlocked();
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
	ll t=input();
	while(t--)
	{
		ll n = input(),i,j,k;
		for(i=0;i<n;i++)
			a[i] = input();
		for(i=0;i<n;i++)
		{
			ll maxi=0,x=1;
			for(j=1;j<=3;j++)
			{
				ll s1=0,s2=0;
				for(k=0;k<j;k++)
					s1+=a[i+k];
				for(k=0;k<j;k++)
					s2+=a[i+j+k];
				if(s1>maxi)
				{
					x = j;
					maxi = s1;
				}
			}
		}
	}
	return 0;
}
