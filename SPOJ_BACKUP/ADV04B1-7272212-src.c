#include<stdio.h>
#define mod 1000003
typedef long long int ull;
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
ull a[mod];
int main()
{
	a[0]=1;
	a[1]=3;
	ull i,x;
	for(i=2;i<=1000000;i++)
	{
		x = power(i,1000001);
		a[i] = (((3*(2*i-1)*a[i-1] - (i-1)*a[i-2]+mod+i*i*mod))%mod*x)%mod;
	}
	ull t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",a[n-1]);
	}
}
