#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,m,i,j,budget;
		scanf("%d%d",&budget,&n);
		int w[n+1],table[n+1][budget+1],v[n+1];
		for(i=0;i<=budget;i++)
			table[0][i] = 0;
		for(i=1;i<=n;i++)
			scanf("%d%d",&w[i],&v[i]);
		for(i=1;i<=n;i++)
			for(j=0;j<=budget;j++)
			{
				if(j>=w[i])
				{
					if(table[i-1][j] > table[i-1][j-w[i]] + v[i])
						table[i][j] = table[i-1][j];
					else
						table[i][j] = table[i-1][j-w[i]] + v[i];
				}
				else
					table[i][j] = table[i-1][j];
			}
		printf("Hey stupid robber, you can get %d.\n",table[n][budget]);
	}
	return 0;
}
