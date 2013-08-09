#include<stdio.h>
#include<string.h>
#define gc getchar_unlocked
typedef long long int ll;
ll power(ll n ,ll k,ll mod)
{
	ll ans=1;
	while(k>0)
	{
		if(k&1)
			ans = (ans*n)%mod;
		k>>=1;
		n = (n * n)%mod;
	}
	return ans%mod;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll mod;
		char a[10000];
		scanf("%s%lld",a,&mod);
		int n = strlen(a),i;
		ll ans = 0;
		for(i=0;i<n;i++)
			ans = (ans + (((a[i]-'0')*power(11,n-1-i,mod))%mod)*power(2,i,mod))%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
