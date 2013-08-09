#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)>0)
	{
		int smoke[n][n],color[n][n],i,j,k,min,sum,x;
		for(i=0;i<n;i++)
		{
			scanf("%d",&color[i][i]);
			smoke[i][i] = 0;
		}
		for(i=0;i<n;i++)
		{
			sum = color[i][i];
			for(j=i+1;j<n;j++)
			{
				sum += color[j][j];
				color[i][j] = sum % 100;
			}
		}
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=n-i+1;j++)
			{
				x = i+j-1;
				smoke[j][x] = 1<<30;
				for(k=j;k<x;k++)
				{
					min = smoke[j][k]+smoke[k+1][x]+color[j][k]*color[k+1][x];
					if(min < smoke[j][x])
						smoke[j][x] = min;
				}
			}
		}
		printf("%d\n",smoke[0][n-1]);
	}
	return 0;
}
