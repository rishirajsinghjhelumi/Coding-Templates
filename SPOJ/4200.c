#include<stdio.h>
#include<cmath>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		double ans,theta,x,y,v,k1,k2,pi=2*acos(0);
		scanf("%lf%lf%lf",&v,&k1,&k2);
		x=-1.0*4.0*(k1/k2);
		theta = pi/2+atan(x)/2;
		ans = (2*k1*v*v*sin(theta)*cos(theta))/10 + (k2*v*v*sin(theta)*sin(theta))/20;
		printf("%.3lf %.3lf\n",theta,ans);
	}
	return 0;
}
