#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(n!=-1 && m!=-1)
	{
		int x,i;
		long long int ans=0,count=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(i==0)
				ans += x*m;
			else
			{
				ans +=count*m;
				ans +=x*m;
			}
			count+=x;
		}
		printf("%lld\n",ans);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
