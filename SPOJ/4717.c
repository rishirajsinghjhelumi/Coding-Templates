#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		unsigned long long int n,count=0,a,b;
		long double ratio;
		scanf("%llu%llu%llu",&n,&a,&b);
		ratio = (b*1.0)/a;
		printf("%llu %llu\n",a,b);
		if(a==b)
			count = ((n+1)*(n+2))/2;
		else
		{
			printf("r==%Lf\n",ratio);
			count = n*(n+1)/2;
			count = (unsigned long long int)(count/ratio);
			count = count + n + 1;
		}
		printf("%llu\n",count);
	}
	return 0;
}
