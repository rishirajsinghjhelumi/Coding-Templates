#include<stdio.h>
int main()
{
	int a[1010000],i=0,k=1,start=2,prev=2,j;
	a[1] = 1;
	while(start<=1000000)
	{
		for(j=0;j<a[k];j++)
			a[j+start] = k+1;
		start = start + a[k];
		k++;
	}
	int test_cases,t;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
			printf("1\n");
		else if(n==2)
			printf("2\n");
		else
			printf("%d\n",a[n-1]);
	}
	return 0;
}
