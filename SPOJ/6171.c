#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,a[2002]={0},i,x,count,d=0,num;
		scanf("%d",&n);
		count = n/2 + 1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[x+1000]++;
			if(a[x+1000] >= count)
			{
				d=1;
				num = x;
			}
		}
		if(d==1)
			printf("YES %d\n",num);
		else
			printf("NO\n");
	}
	return 0;
}
