#include<stdio.h>
#include<math.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		long long int n;
		int i,j,k=0;
		scanf("%lld",&n);
		int x=sqrt(n);
		for(i=0;i<=x;i++)
		{
			for(j=i;j<=x;j++)
			{
				if(i*i+j*j==n)
				{
					k=1;
					break;
				}
			}
			if(k==1)
				break;
		}
		printf("%s\n",k==1?"YES":"NO");
	}
	return 0;
}
