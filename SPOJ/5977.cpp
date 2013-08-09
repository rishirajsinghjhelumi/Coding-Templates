#include<stdio.h>
#include<algorithm>
#define mod 1000000007
typedef long long int ll;
ll f[200010];
int main()
{
	ll test_cases;
	scanf("%lld",&test_cases);
	while(test_cases--)
	{
		ll a,b,c,n,i=0,sum=1,m;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		f[1] = 1;
		for(i=2;i<=n;i++)
		{
			std::nth_element(f+1,f+i/2,f+i);
			m = f[i/2];
			f[i] = (a*m+b*i+c)%mod;
			sum = (sum + f[i]);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
