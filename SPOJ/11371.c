#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,r,x,y,i,j;
		scanf("%d%d",&n,&r);
		int l[n],a[n][n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				a[i][j]=0;
			l[i] = 0;
		}
		while(r--)
		{
			scanf("%d%d",&x,&y);
			a[x][y] = 1;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ",a[i][j]);
				if(a[i][j]==1)
				{
					if(l[j] < l[i]+1)
						l[j] = l[i] + 1;
				}
			}
			printf("\n");
		}
		for(i=0;i<n;i++)
			printf("%d ",l[i]);
		printf("\n");
	}
	return 0;
}
