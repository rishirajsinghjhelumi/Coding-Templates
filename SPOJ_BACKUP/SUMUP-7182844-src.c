#include<stdio.h>
typedef long double ld;
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ld n,ans;
		scanf("%Lf",&n);
		ans = 0.5*(1-(1.0/((n+1)*(n+1)-n)));
		printf("%.5Lf\n",ans);
	}
	return 0;
}
