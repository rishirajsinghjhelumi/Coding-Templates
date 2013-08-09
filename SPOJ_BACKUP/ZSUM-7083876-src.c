#include<stdio.h>
typedef unsigned long long int ull;
ull mod = 10000007;
ull power(ull n ,ull k)
{
	ull temp = 1,ans=1;
	while(k>0)
	{
		if(k&temp)
		{
			ans = (ans*n)%mod;
			k-=temp;
		}
		temp <<=1;
		n = (n * n)%mod;
	}
	return ans%mod;
}
int main()
{
	while(1)
	{
		ull n,k;
		scanf("%llu%llu",&n,&k);
		if(n==0 && k==0)
			break;
		printf("%llu\n",( power(n,n)%mod + power(n,k)%mod + 2*( power(n-1,k)%mod + power(n-1,n-1)%mod )%mod)%mod);
	}
	return 0;
}
