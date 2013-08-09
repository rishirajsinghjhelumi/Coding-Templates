#include<stdio.h>
#include<math.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		long double a,b,c,d,s,ans;
		scanf("%Lf%Lf%Lf%Lf",&a,&b,&c,&d);
		s = (a+b+c+d)/2;
		ans = sqrt((s-a)*(s-b)*(s-c)*(s-d));
		printf("%.2Lf\n",ans);
	}
	return 0;
}
