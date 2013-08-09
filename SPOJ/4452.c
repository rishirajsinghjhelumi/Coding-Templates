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
		for(i=0;c!='=';i++)
		{
			if(i%2==0)
			{
				scanf("%lld",&a);
				if(c=='*')
					ans = ans * a;
				else if(c=='/')
					ans = ans / a;
				else if(c=='+')
					ans = ans + a;
				else if(c=='-')
					ans = ans - a;
			}
			else
				scanf("%c",&c);
			scanf("%c",&ch);
		}
		printf("%lld\n",ans);
		scanf("%*c");
	}
	return 0;
}
