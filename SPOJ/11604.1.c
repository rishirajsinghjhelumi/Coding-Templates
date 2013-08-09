#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		long long int x,y,z,i,done=0;
		scanf("%lld%lld%lld",&x,&y,&z);
		for(i=z+1;i<=x-1;i++)
		{
			if(((2*i*z)/(i*i-z*z))==(y/(x-i)))
			{
				done = i;
				break;
			}
		}
		if(done!=0)
			printf("%lld\n",done);
		else
			printf("Not this time.\n");
	}
	return 0;
}
