#include<stdio.h>
int main()
{
	long long int a[51],i,ans[51],x,y;
	a[1] = 2;
	a[2] = 3;
	for(i=3;i<50;i+=2)
		a[i] = a[i+1] = 3*a[i-2];
	ans[1]=2;
	for(i=2;i<=50;i++)
		ans[i] = ans[i-1]+a[i];
	ans[1]=3;
	a[1]=3;
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		scanf("%lld%lld",&x,&y);
	}
	return 0;
}
