#include<stdio.h>
int mod = 1000000007;
typedef long long int ll;
ll a[1010][1010];
int main()
{
	ll test_cases,n,k;
	for(n=1000;n>=1;n--)
		for(k=1000;k>=1;k--)
		{
			if(k>n)
				a[n][k] = 0;
			else if(k>(n>>1))
				a[n][k] = 1;
			else
				break;
		}
	for(n=2;n<=1000;n++)
		for(k=(n>>1);k>=1;k--)
			a[n][k] = (a[n][k+1]+a[n-k][k])%mod;
	scanf("%lld",&test_cases);
	while(test_cases--)
	{
		scanf("%lld%lld",&n,&k);
		printf("%lld\n",a[n][k]);
	}
	return 0;
}
