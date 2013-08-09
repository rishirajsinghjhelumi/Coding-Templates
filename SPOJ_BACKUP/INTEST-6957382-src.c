#include<stdio.h>
int main()
{
	int n,k,i,a,count=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a%k==0)
			count++;
	}
	printf("%d\n",count);
	return 0;
}
