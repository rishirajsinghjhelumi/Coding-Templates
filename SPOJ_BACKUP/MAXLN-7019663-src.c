#include<stdio.h>
int main()
{
	int test_cases,i;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		int r;
		scanf("%d",&r);
		double ans=0;
		ans=4.0*r*r+0.25;
		printf("Case %d: %.2f\n",i+1,ans);
	}
	return 0;
}
