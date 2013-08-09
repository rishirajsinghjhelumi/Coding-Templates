#include<stdio.h>
typedef unsigned long long int ull;
ull a[1000010];
int main()
{
	ull i;
	a[1] = 0;
	a[2] = 1;
	for(i=3;i<=1000000;i++)
		a[i] = ((i-1)*(a[i-1]+a[i-2]))%1000000007;
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ull n;
		scanf("%llu",&n);
		printf("%llu\n",a[n]);
	}
	return 0;
}
