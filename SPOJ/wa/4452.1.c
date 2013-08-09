#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	scanf("%*c%*c");
	while(test_cases--)
	{
		long long int ans=1,a;
		char ch='*',c='*';
		int i;
		while(c!='=')
		{
			scanf("%c",&c);
			if(c>=48 || c<=57)
			{
				a=0;

			}
		}
		scanf("%*c");
		printf("%lld\n",ans);
	}
	return 0;
}
