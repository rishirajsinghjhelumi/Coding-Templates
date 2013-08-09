#include<stdio.h>
int f(int n)
{
	if(n==0 || n==1)
		return 1;
	if(n==2)
		return 5;
	if(n==3)
		return 11;
	return f(n-1)+5*f(n-2)+f(n-3)-f(n-4);
}
int main()
{
	int test_cases,t=1;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n;
		scanf("%d",&n);
		printf("%d %d\n",t++,f(n));
	}
	return 0;
}
