#include<stdio.h>
int main()
{
	unsigned long long int a[1000010],i,mod = 1000000003;
	a[1] = 1;
	for(i=2;i<=1000000;i++)
		a[i] = (a[i-1] + (i*i*i)%mod)%mod;
	for(i=2;i<=1000000;i++)
		a[i] = (a[i-1] +a[i])%mod;
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,i;
		scanf("%d",&n);
		printf("%llu\n",a[n]);
	}
	return 0;
}
