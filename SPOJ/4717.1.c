#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int i;
		unsigned long long int a,b,count=0,n;
		long double ratio;
		scanf("%lld%llu%llu",&n,&a,&b);
		ratio = (b*1.0)/a;
		if(a==b)
			count = ((n+1)*(n+2))/2;
		else
		{
			for(i=0;i<=n;i++)
				count = count  + (int)(i/ratio);
			count +=n+1;
		}
		printf("%llu\n",count);
	}
	return 0;
}
