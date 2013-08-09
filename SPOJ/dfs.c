#include<stdio.h>
void dfs1(int n,int f[],int d[],int color[],int parent[]);
void visit(int v,int f[],int d[],int color[],int parent[],int n);
int a[1000][1000];
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,r,x,y,i,j;
		scanf("%d%d",&n,&r);
		int f[n],d[n],color[n],parent[n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				a[i][j]=0;
			color[i] = parent[i] = 0;
		}
		while(r--)
		{
			scanf("%d%d",&x,&y);
			a[x][y] = 1;
		}
		dfs1(n,f,d,color,parent);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
		for(i=0;i<n;i++)
			printf("%d ",d[i]);
		printf("\n");
		for(i=0;i<n;i++)
			printf("%d ",f[i]);
		printf("\n");
	}
	return 0;
}
int time;
void dfs1(int n,int f[],int d[],int color[],int parent[])
{
	int i,j,k;
	time=0;
	for(i=0;i<n;i++)
		if(color[i]==0)
		{
			color[i]=1;
			visit(i,f,d,color,parent,n);
		}
}
void visit(int v,int f[],int d[],int color[],int parent[],int n)
{
	d[v] = ++time;
	int i;
	for(i=0;i<n;i++)
		if(a[v][i]==1 && color[i] ==0)
		{
			color[i] = 1;
			parent[i] = v;
			visit(i,f,d,color,parent,n);
		}
	color[v] = 2;
	f[v] = ++time;
}
