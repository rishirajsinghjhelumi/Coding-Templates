#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long int ull;
int main()
{
	ull test_cases,t;
	scanf("%llu",&test_cases);
	for(t=0;t<test_cases;t++)
	{
		int n,i,j,c,b,l=0,x=0,u,s=0,e,m,bipar=1,v,n1,n2;
		scanf("%d%d",&n,&m);
		int a[n][n],q[100000],color[n],partition[n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				a[i][j] = 0;
			color[i] = 0;
			partition[i] = 0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&n1,&n2);
			a[n1-1][n2-1] = 1;
			a[n2-1][n1-1] = 1;
		}
		for(j=0;j<n;j++)
		{
			if(color[j]==0)
			{
				l=x=0;
				s=j;
				color[s] = 1;
				partition[s] = 1;
				q[l++] = s;
				while(x!=l)
				{
					u=q[x++];
					for(i=0;i<n;i++)
						if(a[u][i]==1)
						{
							if(partition[i]==partition[u])
							{
								bipar=0;
								break;
							}
							else if(color[i]==0)
							{
								color[i] = 1;
								partition[i] = 3-partition[u];
								q[l++] = i;
							}
						}
					if(bipar==0)
						break;
				}
			}
			if(bipar==0)
				break;
		}
		printf("Scenario #%llu:\n",t+1);
		printf("%s\n",bipar==1?"No suspicious bugs found!":"Suspicious bugs found!");
	}
	return 0;
}
