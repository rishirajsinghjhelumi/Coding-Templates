#include<stdio.h>
long long int max;
int summer(int a[],int n,int w,long long int sum,int term);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,w,i,x;
		long long int sum=0;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		max = -99999;
		if(n>=3)
			summer(a,n,2,a[0]+2*a[1],2);
		else
		{
			if(n==1)
				max = a[0];
			if(n==2)
				max = a[0] + 2*a[1];
		}
		printf("%lld\n",max);
	}
	return 0;
}
int summer(int a[],int n,int w,long long int sum,int term)
{
	if(term==n)
	{
		if(sum > max)
			max = sum;
		return;
	}
	if(a[term] > 0)
		summer(a,n,w+1,sum+a[term]*(w+1),term+1);
	else
	{
		int i;
		for(i=2;i<=w+1;i++)
			summer(a,n,i,sum+i*a[term],term+1);
	}
	return;
}
