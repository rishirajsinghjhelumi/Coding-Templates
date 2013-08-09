#include<stdio.h>
int main()
{
	int n,m,i,j,x,y,ans=1;
	scanf("%d%d",&n,&m);
	int parent[n+1];
	for(i=0;i<n+1;i++)
		parent[i] = -1;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		if(ans==0)
			continue;
		if(parent[x] == parent[y] && parent[x]!=-1 && parent[y]!=-1)
			ans=0;
		if(parent[x] == -1 && parent[y] == -1)
			parent[x] = x,parent[y] = x;
		else if(parent[x]!=-1 && parent[y] == -1)
			parent[y] = parent[x];
		else if(parent[x]==-1 && parent[y]!=-1)
			parent[x] = parent[y];
		else if(parent[x]!=parent[y])
		{
			for(j=1;j<n+1;j++)
				if(parent[j] == parent[y])
					parent[j] = parent[x];
		}
	}
	printf("%s\n",ans==1?"YES":"NO");
	return 0;
}
