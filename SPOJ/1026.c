#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,i;
		scanf("%d",&n);
		double s=0.0;
		for(i=1;i<=n;i++)
			s+=(n*1.0)/i;
		printf("%.2f\n",s);
	}
	return 0;
}
