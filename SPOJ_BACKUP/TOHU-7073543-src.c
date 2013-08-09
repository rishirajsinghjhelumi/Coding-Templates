#include<stdio.h>
int main()
{
	long long int test_cases;
	scanf("%lld",&test_cases);
	while(test_cases--)
	{
		long long int x;
		scanf("%lld",&x);
		long double a = 0.5+0.5*(0.5-(1.0/((x+1)*(x+2))));
		printf("%.11Lf\n",a);
	}
	return 0;
}
