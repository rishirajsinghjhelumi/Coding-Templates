#include<stdio.h>
int main()
{
	int n,m,i,j,budget;
	scanf("%d%d",&budget,&n);
	while(budget!=0 && n!=0)
	{
		int w[n+1],table[110][600],v[n+1];
		int amount = 0;
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
		int we=budget;
		for(j=n;j>0;j--)
			if(table[j][we]!=table[j-1][we])
			{
				amount += w[j];
				we -= w[j];
			}
		printf("%d %d\n",amount,table[n][budget]);
		scanf("%d%d",&budget,&m);
	}
	return 0;
}
