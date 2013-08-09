#include<stdio.h>
int main()
{
	int n,m,x,i=0,j=0;
	long long int max=0,sum=0;
	scanf("%d%d",&n,&m);
	int a[n];
	scanf("%d",&a[i++]);
	if(sum+a[i-1] <= m)
	{
		sum+=a[i-1];
		if(sum > max)
			max = sum;
	}
	n=n-1;
	while(n--)
	{
		scanf("%d",&a[i++]);		
		sum+=a[i-1];
		if(sum <= m)
		{
			if(sum > max)
				max = sum;
		}
		else
		{
			while(sum>m)
			{
				sum = sum - a[j];
				j++;
			}
			if(sum > max)
				max = sum;
		}
		if(max==m)
			break;
	}
	printf("%lld\n",max);
	return 0;
}
