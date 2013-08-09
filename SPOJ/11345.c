#include<stdio.h>
unsigned long long int gcd(int a,int b);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		unsigned long long int a,b,ans=0,i,lcm;
		scanf("%llu%llu",&a,&b);
		for(i=a;i<b;i++)
		{
			lcm = (i*b)/gcd(i,b);
			ans = ans + lcm % 1000000007;
		}
		printf("%llu\n",ans+b);
	}
	return 0;
}
unsigned long long int gcd(int a,int b)
{
	int i,temp,c;
	if(a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	while(b != 0)
	{
		c = a;
		a = b;
		b = c % b;
	}
	return a;
}
