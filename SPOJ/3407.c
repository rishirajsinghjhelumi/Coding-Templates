#include<stdio.h>
int max_table(int a[],int n)
{
	int table[n+2],i;
	table[n] = table[n+1] = 0;
	for(i=n-1;i>=0;i--)
		table[i] = (a[i]+table[i+2]>table[i+1])?a[i]+table[i+2]:table[i+1];
	return table[0];
}
int main()
{
	int m,n,i,j;
	while(scanf("%d%d",&m,&n)==2 && (m|n)!=0)
	{
		int ans[m],a[n];
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d",&a[j]);
			ans[i] = max_table(a,n);
		}
		printf("%d\n",max_table(ans,m));
	}
	return 0;
}
