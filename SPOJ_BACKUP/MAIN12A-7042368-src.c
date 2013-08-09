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
		//printf("s==%d val==%d a[s]==%d\n",start,k+1,a[start-1]);
		k++;
	}
	int test_cases,t;
	scanf("%d",&test_cases);
	for(t=1;t<=test_cases;t++)
	{
		int n;
		scanf("%d",&n);
		printf("Case #%d: %d\n",t,a[n]);
	}
	return 0;
}
