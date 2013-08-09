#include<stdio.h>
int main()
{
	int test_cases,i,j,k,a,x=1,count=0;
	long int number;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		x=a=1;
		scanf("%ld",&number);
		while(a!=0)
		{
			x=x*5;
			a=number/x;
			count=count+a;
		}
		printf("%d\n",count);
		count=0;
	}
	return 0;
}
