#include<stdio.h>
int main()
{
	int test_cases,t;
	scanf("%d",&test_cases);
	for(t=1;t<=test_cases;t++)
	{
		int n,p,i,j,x,sum,c1=1,c2=1,c3=1;
		scanf("%d%d",&n,&p);
		int solved[50]={0};
		for(i=0;i<n;i++)
		{
			sum = 0;
			for(j=0;j<p;j++)
			{
				scanf("%d",&x);
				if(x)
					solved[j] = 1;
				sum += x;
			}
			if(sum==p)
				c3 = 0;
			if(!sum)
				c2 = 0;
		}
		for(i=0;i<p;i++)
			if(!solved[i])
			{
				c1 = 0;
				break;
			}
		x = (c1<<2)+(c2<<1)+c3;
		printf("Case %d: %d\n",t,x);
	}
	return 0;
}
