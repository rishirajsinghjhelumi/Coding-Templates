#include<stdio.h>
int main()
{
	int n,m,i,j,budget;
	while(scanf("%d%d",&budget,&n)&&(budget|n))
	{
		int w[110],table[110][600]={0},v[110];
		int amount = 0,x;
		for(i=1;i<=n;i++)
			scanf("%d%d",&w[i],&v[i]);
		for(i=1;i<=n;i++)
			for(j=0;j<=budget;j++)
			{
				x=w[i];
				if(j>=x)
				{
					if(table[i-1][j] > table[i-1][j-x] + v[i])
						table[i][j] = table[i-1][j];
					else
						table[i][j] = table[i-1][j-x] + v[i];
				}
				else
					table[i][j] = table[i-1][j];
			}
		int we=budget;
		while(i--)
			if(table[i][we]!=table[i-1][we])
			{
				amount += w[i];
				we -= w[i];
			}
		printf("%d %d\n",amount,table[n][budget]);
	}
	return 0;
}
