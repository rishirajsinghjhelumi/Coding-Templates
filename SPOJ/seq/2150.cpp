#include<stdio.h>
#include<algorithm>
#include<map>
#define max 1000000
typedef long long int ll;
using namespace std;
map<ll,int>sum;
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
	ll test_cases = input();
	while(test_cases--)
	{
		sum.clear();
		sum[0] = 1;
		ll count=0,s=0,n,x;
		n = input();
		while(n--)
		{
			s+=input();
			count += sum[s-47];
			sum[s]++;
		}
		printf("%lld\n",count);
	}
	return 0;
}
