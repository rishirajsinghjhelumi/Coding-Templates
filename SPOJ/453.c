#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,i,j,k,max;
		scanf("%d",&n);
		int a[n][n];
		for(i=0;i<n;i++)
			for(j=0;j<=i;j++)
				scanf("%d",&a[i][j]);
		for(i=1;i<n;i++)
			for(j=0;j<=i;j++)
			{
				if(j==0)
					a[i][j] += a[i-1][j];
				else if(j==i)
					a[i][j] += a[i-1][j-1];
				else
				{
					if(a[i-1][j] > a[i-1][j-1])
						a[i][j] += a[i-1][j];
					else
						a[i][j] += a[i-1][j-1];
				}
			}
		max = a[0][0];
		for(i=0;i<n;i++)
			if(a[n-1][i] > max)
				max = a[n-1][i];
		printf("%d\n",max);
	}
	return 0;
}
