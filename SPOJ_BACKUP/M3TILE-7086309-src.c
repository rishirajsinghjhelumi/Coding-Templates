#include<stdio.h>
int g(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return f(n-1) + g(n-2);
}
int f(int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return 0;
	return f(n-2)+2*g(n-1);
}
int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==-1)
			break;
		if(n&1)
			printf("0\n");
		else
			printf("%d\n",f(n));
	}
	return 0;
}
