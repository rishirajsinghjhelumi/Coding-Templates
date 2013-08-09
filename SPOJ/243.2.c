#include<stdio.h>
#include<assert.h>
int boy[1000][1000],girl[1000][1000],g[1000],pair[1000],queue[100000],rank[1000];
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,i,j,k,x,l=0,done;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			x--;
			for(j=0;j<n;j++)
				scanf("%d",&girl[x][j]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			x--;
			queue[i] = x;
			for(j=0;j<n;j++)
				scanf("%d",&boy[x][j]);
			g[i] = -1;
			rank[i] = 0;
		}
		x=n;
		int X,r,p=0,w;
		while(x!=l)
		{
			X = queue[l];
			assert(X>=0 && X<n);
			w = boy[X][rank[l]]-1;
			assert(w>=0);
			if (g[w] == -1)
			{
				pair[X] = w;
				g[w] = X;
				l++;
				rank[l]++;
			}
			else
			{
				for(i=0;i<n;i++)
					if(girl[w][i] == X+1)
						break;
				for(j=0;j<n;j++)
					if(girl[w][j] == g[w]+1)
						break;
				if(i < j)
				{
					pair[X] = w;
					queue[x++] = g[w];
					g[w] = X;
					rank[l++]++;
				}
				else
					rank[l]++;
			}
		}
		for(i=0;i<n;i++)
			printf("%d %d\n",i+1,pair[i]+1);
	}
	return 0;
}
