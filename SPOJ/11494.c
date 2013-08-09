#include<stdio.h>
#include<math.h>
int main()
{
	int test_cases,t;
	scanf("%d",&test_cases);
	for(t=1;t<=test_cases;t++)
	{
		double g = 9.806,d,v,angle,theta;
		scanf("%lf%lf",&d,&v);
		angle = d * g / (v*v);
		if(angle > 1 || angle < -1)
		{
			printf("Scenario #%d: -1\n",t);
			continue;
		}
		theta = asin(angle)/2;
		printf("Scenario #%d: %.2lf\n",t,(theta*180)/(2*acos(0.0)));
	}
	return 0;
}
