#include<stdio.h>
int x=0,n,t;
c(int a,int b)
{
	if(a==n&&b==n)
	{
		x++;
		return;
	}
	if(a+1<=n)
		c(a+1,b);
	if(b+1<=n)
		c(a,b+1);
}
main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		c(0,0);
		printf("%lld\n",x);
		x=0;
	}
}
