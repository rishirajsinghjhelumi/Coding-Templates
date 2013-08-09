#include<stdio.h>
typedef unsigned long long int ull;
ull mod = 1000000007;
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
	int i,j;
	ull a[1000010];
	a[0] = 1;
	a[1] = 1;
	for(i=2;i<=1000000;i++)
		a[i] = (a[i-1] + a[i-2])%1000000006;
	ull test_cases;
	scanf("%llu", &test_cases);
	while(test_cases--)
	{
		ull n;
		scanf("%llu",&n);
		printf("%llu\n",power(2,a[n-1]));
	}
	return 0;

}
