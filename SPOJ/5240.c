#include<stdio.h>
#include<math.h>
#define three sqrt(3)
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		long double a,b,c,a1,a2;
		scanf("%Lf%Lf%Lf",&a,&b,&c);
		a1 = (three*(a*a+b*b+c*c))/8;
		a2 = (3*(sqrt((a+b+c)*(a+b-c)*(b+c-a)*(a+c-b))))/8;
		printf("%.2Lf\n",a1+a2);
	}
	return 0;
}
