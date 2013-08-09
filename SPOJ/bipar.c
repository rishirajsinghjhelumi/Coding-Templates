#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,c,b,l=0,x=0,u,s=0,e,m,bipar=1,v;
	scanf("%d",&n);
	int a[n][n],q[100000],color[n],dist[n],partition[n],auth[n],list1[n],list2[n],l1=0,l2=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
		color[i] = 0;
		dist[i] = 9999;
		partition[i] = 0;
	}
	l=x=s=0;
	color[s] = 1;
	dist[s] = 0;
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
					dist[i] = dist[u] + 1;
					partition[i] = 3-partition[u];
					q[l++] = i;
				}
			}
		color[u] = 2;
		if(bipar==0)
			break;
	}
	if(bipar==0)
		printf("NO\n");
	else
	{
		printf("YES\n");
		for(i=0;i<n;i++)
			if(partition[i] == 1)
				printf("%d ",i+1);
		printf("\n");
		for(i=0;i<n;i++)
			if(partition[i] == 2)
				printf("%d ",i+1);
		printf("\n");
	}
	return 0;
}
