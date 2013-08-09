#include<stdio.h>
int main()
{
	double n,sum;
	scanf("%lf",&n);
	while(n!=0.00)
	{
		int count = 2;
		sum=0.00;
		while(sum<n)
		{
			sum+=1.0/count;
			count++;
		}
		printf("%d card(s)\n",count-2);
		scanf("%lf",&n);
	}
	return 0;
}
