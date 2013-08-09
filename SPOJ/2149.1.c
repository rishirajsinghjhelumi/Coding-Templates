#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,x,i;
		long long int count =0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%*s%d",&x);
			count+=abs(x-i);
		}
		printf("%lld\n",count);
	}
	return 0;
}
