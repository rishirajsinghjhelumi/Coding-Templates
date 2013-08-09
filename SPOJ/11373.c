#include<stdio.h>
int main()
{
	int test_cases,t;
	scanf("%d",&test_cases);
	for(t=1;t<=test_cases;t++)
	{
		int n,i,x;
		long long int power=1,start=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			power += x;
			if(power < 1)
			{
				start += -1*power+1;
				power = 1;
			}
		}
		printf("Scenario #%d: %lld\n",t,start);
	}
	return 0;
}
