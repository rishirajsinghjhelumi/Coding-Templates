#include<stdio.h>
#include<math.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n;
		unsigned long long int a=0,b=1;
		scanf("%d",&n);
		a = pow(2,n+1)-1;
		printf("%llu\n",a%);
	}
	return 0;
}
