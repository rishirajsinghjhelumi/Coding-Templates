#include<stdio.h>
#include<math.h>
int main()
{
	int n,num,x,p=1,i;
	scanf("%d",&n);
	num = (1+sqrt(1+8*n))/2;
	for(i=1;i<=num;i++)
	{
		scanf("%d",&x);
		printf("%d ",x-p);
		p = x - p;
	}
	printf("\n");
	return 0;
}
