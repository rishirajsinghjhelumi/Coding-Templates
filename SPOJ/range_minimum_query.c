#include<stdio.h>
#include<math.h>
#define log2(x) log(x)/log(2)
int m[100010][50],a[100010];
int main()
{
	int test,t;
	scanf("%d",&test);
	for(t=1;t<=test;t++)
	{
		int n,i,j,q,b,k;
		scanf("%d%d",&n,&q);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			m[i][0] = i;
		for(j=1;1<<j<=n;j++)
			for(i=0;i+(1<<j)-1<n;i++)
			{
				if( a[m[i][j-1]] < a[m[i+(1<<(j-1))][j-1]] )
					m[i][j] = m[i][j-1];
				else
					m[i][j] = m[i+(1<<(j-1))][j-1];
			}
		printf("Scenario #%d:\n\n",t);
		while(q--)
		{
			scanf("%d%d",&i,&j);
			j--;
			i--;
			k = log2(j-i+1);
			if (a[m[i][k]] <= a[m[j-(1<<k)+1][k]] )
				b = m[i][k];
			else
				b = m[j-(1<<k)+1][k];
			printf("%d\n",a[b]);
		}
	}
	return 0;
}
