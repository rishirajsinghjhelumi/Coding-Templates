#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		long long int a;
		scanf("%lld",&a);
		if(a<=4)
			printf("%lld\n",192+(250*((a-1)%4)));
		else
			printf("%lld%lld\n",(a-1)/4,192+(250*((a-1)%4)));
	}
	return 0;
}
