#include<stdio.h>
int gcd(int a,int b);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		unsigned long long int ans=0;
		int a,i;
		scanf("%d",&a);
		for(i=1;i<a;i++)
		{
			//if(i%a==0)
				ans = (ans + (i*a)/gcd(i,a));
			//else
			//	ans = (ans + (i*a));
		}
		printf("%llu\n",ans+a);
	}
	return 0;
}
int gcd(int a,int b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
