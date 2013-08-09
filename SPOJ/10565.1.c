#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,i,j;
		scanf("%d",&n);
		int a[n+1],unmarked = n-1;
		for(i=2;i<=n;i++)
			a[i] = 0;
		for(i=n;i>=2;i--)
		{
			if(a[i] == 0)
			{
				for(j=2;j<=i/2;j++)
				{
					if(i%j == 0)
					{
						if(a[j]!=1)
						{
							unmarked--;
							a[j] = 1;
						}
					}
				}
			}
		}
		printf("%d\n",unmarked);
	}
	return 0;
}
