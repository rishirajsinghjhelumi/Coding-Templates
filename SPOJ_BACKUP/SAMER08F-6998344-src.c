#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		int a=0,i;
		for(i=1;i<=n;i+=1)
			a+=i*i;
		printf("%d\n",a);
		scanf("%d",&n);
	}
	return 0;
}
