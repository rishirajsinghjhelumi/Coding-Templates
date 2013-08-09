#include<stdio.h>
#include<math.h>
int main()
{
	long double l,w,r,b;
	scanf("%Lf%Lf",&r,&b);
	l = ((4+r)+sqrt((r-4)*(r-4)-16*b))/4;
	w = (r+b)/l;
	printf("%.0Lf %.0Lf\n",l,w);
	return 0;
}
