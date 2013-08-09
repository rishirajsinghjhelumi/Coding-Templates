#include <stdio.h>
int main()
{
	int i,n,j,x,temp;
	scanf("%d",&n);
	while(n!=-1)
	{
		int a[n];
		long long int moves=0,sum=0;
		double avg,y;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		avg=(sum*1.0)/n;
		temp=(int)avg;
		y=temp*1.0;
		if(avg!=y)
		{
			printf("-1\n");
			scanf("%d",&n);
			continue;
		}
		for(i=0;i<n;i++)
		{
			if(a[i] < temp)
				moves += temp-a[i];
		}
		printf("%lld\n",moves);
		scanf("%d",&n);
	}
	return 0;
}
