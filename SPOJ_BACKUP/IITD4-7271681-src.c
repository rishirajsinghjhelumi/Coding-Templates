#include<stdio.h>
#define mod 1000000007
#define max 100000
typedef unsigned long long int ull;
//ull div[max+10][150];
//ull ind[max+10];
ull power(ull n ,ull k)
{
	ull ans=1;
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
	ull i,j;
	//for(i=1;i<=max;i++)
	//	for(j=i;j<=max;j+=i)
	//		div[j][ind[j]++] = i;
	ull t,a,b,k;
	scanf("%llu",&t);
	while(t--)
	{
		scanf("%llu%llu%llu",&a,&b,&k);
		ull x[max+10]={0},l,f;
		a--;
		ull ans = b-a;
		for(i=2;i<=b;i++)
		{
			l = b/i-a/i;
			ans = (ans+l*power(i,k))%mod;
		}
		printf("%llu\n",ans);
	}
	return 0;
}
