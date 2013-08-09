#include<stdio.h>
int check(int );
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,x;
		scanf("%d",&n);
		x=n;
		while(1)
		{
			if(check(n)==1)
				break;
			n+=x;
		}	
		printf("%d\n",n);
	}
	return 0;
}
int check(int n)
{
	while(n!=0)
	{
		if(n%10==1 || n%10==0)
		{
			n/=10;
			continue;
		}
		return 0;
	}
	return 1;
}
