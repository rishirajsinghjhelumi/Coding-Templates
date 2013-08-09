#include<stdio.h>
#include<math.h>
int main()
{
	char ch;
	long double x[2],y[2],distance=0.0;
	int i=0;
	while(scanf("%c",&ch)!=EOF)
	{
		if(ch=='(')
		{
			scanf("%Lf%*c%*c%Lf",&x[i],&y[i]);
			i++;
		}
		if(i==2)
		{
			distance += sqrt( ((x[1]-x[0]) * (x[1]-x[0])) + ((y[1]-y[0]) * (y[1]-y[0])) );
			printf("The salesman has traveled a total of %.3Lf kilometers.\n",distance);
			x[0] = x[1];
			y[0] = y[1];
			i--;
		}
	}
	return 0;
}
