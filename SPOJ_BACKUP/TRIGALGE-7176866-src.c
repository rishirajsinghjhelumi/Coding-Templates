#include<stdio.h>
#include<math.h>
typedef long double ld;
ld a,b,c;
ld f(ld x)
{
	return a*x+b*sin(x)-c;
}
ld fdx(ld x)
{
	return a+b*cos(x);
}
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		scanf("%Lf%Lf%Lf",&a,&b,&c);
		ld px = c/a,x;
		int i;
		for(i=0;i<100;i++)
		{
			x = px - f(px)/fdx(px);
			px = x;
		}
		printf("%.6Lf\n",x);
	}
	return 0;
}
