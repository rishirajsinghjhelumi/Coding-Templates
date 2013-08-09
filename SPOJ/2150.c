#include<stdio.h>
int main()
{
	int i,test_cases;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		int n,j,k,l,count = 0,sum = 0,check = 0,sum1 = 0;
		scanf("%d",&n);
		int a[n];
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		for(j=0;j<n;j++)
		{
			sum = 0;
			for(k=j;k<n;k++)
			{
				for(l=j;l<=k;l++)
				{
					sum += a[l];
					if(sum > 47)
						break;
				}
				if(sum == 47)
					count++;
				sum = 0;
			}
		}
		printf("%d\n",count);
		count = 0;
	}
	return 0;
}
