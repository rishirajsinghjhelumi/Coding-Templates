#include<stdio.h>
int n,i,j,c[1000001]={0},ans[1000001]={0},max=-99999;
int main()
{
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c[a[i]]++;
		if(a[i] > max)
			max = a[i];
	}
	for(i=1;i<=max;i++)
	{
		if(c[i]>0)
		{
			j=i;
			while(j<=max)
			{
				ans[j]+=c[i];
				j+=i;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\n",ans[a[i]]-1);
	return 0;
}
