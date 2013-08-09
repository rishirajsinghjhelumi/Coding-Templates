#include<stdio.h>
int main()
{
	int n,d,i,j,mod=1111111111,ans,x,a=1,b=1,e,y=2;
	scanf("%d%d",&n,&d);
	int c[d+1];
	for(i=0;i<=d;i++)
		scanf("%d",&c[i]);
	while(n-->1)
	{
		ans=0;
		for(i=0;i<=d;i++)
		{
			x=1;
			for(j=0;j<i;j++)
				x=((x%mod)*(y%mod))%mod;
			x=((x%mod)*(c[i]%mod))%mod;
			ans=(ans+x)%mod;
		}
		e=(a+b+ans)%mod;
		a=b;
		b=e;
		y++;
	}
	printf("%d\n",e);
	return 0;
}
