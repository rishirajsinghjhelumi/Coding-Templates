#include<stdio.h>
#include<math.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		long double n,two=sqrtl(2),ans;
		scanf("%Lf",&n);
		ans = 8*n*n*n*(2-two);
		printf("%.4Lf\n",ans);
	}
	return 0;
}
