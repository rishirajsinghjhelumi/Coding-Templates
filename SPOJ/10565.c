#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n;
		scanf("%d",&n);
		if(n%2==0)
			printf("%d\n",n/2);
		else
			printf("%d\n",n/2+1);
	}
	return 0;
}
