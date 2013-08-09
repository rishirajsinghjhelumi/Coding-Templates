#include <stdio.h>
int main()
{
	int i,n,j,temp,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long int sum=0,x;
		double avg,y;
		int ans=1;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			sum=(sum+x)%n;
		}
		avg=(sum*1.0)/n;
		temp=(int)avg;
		y=temp*1.0;
		if(avg!=y)
			ans=0;
		printf("%s\n",ans==1?"YES":"NO");
	}
	return 0;
}
