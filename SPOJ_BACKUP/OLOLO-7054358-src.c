#include<stdio.h>
int main()
{
	int ans=0,n,x;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		ans ^= x;
	}
	printf("%d\n",ans);
	return 0;
}
