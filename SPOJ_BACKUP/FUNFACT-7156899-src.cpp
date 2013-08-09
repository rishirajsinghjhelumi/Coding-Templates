#include<stdio.h>
#include<cmath>
typedef long long int ll;
ll stirling(ll n)
{
	long double x=n*1.0,res;
	ll ans;
	res = (x*log(x))-x+(0.5*log(2*M_PI*x))+(1.0/12.0/x)-(1.0/360.0/x/x/x)+(1.0/1260.0/x/x/x/x/x);
	ans = (ll)(res*log10(M_E))+1;
	return ans;
}
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ll n;
		scanf("%lld",&n);
		n+=1;
		ll lower = 1, upper = 2147483648 ,mid;
		while(lower<upper)
		{
			mid = (upper+lower)>>1;
			if(stirling(mid)<n)
				lower = mid + 1;
			else
				upper = mid;
		}
		mid = (upper+lower)>>1;
		printf("%lld\n",mid-1);
	}
	return 0;
}
