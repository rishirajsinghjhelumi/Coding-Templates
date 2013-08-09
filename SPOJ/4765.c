#include<stdio.h>
int main()
{
	int a,b;
	int x[1000000]={0},y=0;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		int i,j,count,max=0,n;
		for(i=a;i<=b;i++)
		{
			count=0;
			n=i;
			if(x[i]!=0)
				continue;
			else
			{
				while(n!=1)
				{
		//			printf("n==%d x[n]==%d\n",n,x[n]);
					if(x[n] != 0)
					{
						count = count + x[n];
						break;
					}
					if(n&1)
						n = 3 * n + 1;
					else
						n = n / 2;
					count++;
				}
			}
		//	printf("-------\n");
			x[i] = count;
			if(count>max)
				max = count;
		}
		printf("%d %d %d\n",a,b,max+1);
	}
	return 0;
}
