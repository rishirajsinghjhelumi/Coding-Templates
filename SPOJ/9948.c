#include<stdio.h>
int main()
{
	long long int n,x=1,y=0;
	int i;
	scanf("%lld",&n);
	for(i=0;n>=x;i++)
	{
		if(x==n)
			y=1;
		x=x<<1;
	}
	printf("%s\n",y==1?"TAK":"NIE");
	return 0;
}
