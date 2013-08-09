#include<stdio.h>
#include<cmath>
typedef long long int ll;
ll stirling(ll n)
{
	long double x=n*1.0,res,pi=3.1415926535897932384626434,e=2.7182818284590452353603;
	ll ans;
	res = (x*log(x))-x+(0.5*log(2*pi*x))+(1.0/12.0/x)-(1.0/360.0/x/x/x)+(1.0/1260.0/x/x/x/x/x);
	ans = (ll)(res*log10(e))+1;
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
		if(n==0)
			printf("1\n");
		else
			printf("%lld\n",stirling(n));
	}
	return 0;
}
