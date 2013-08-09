#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		unsigned long long int n,x=1,i,j,c;
		scanf("%llu",&n);
		for(i=0;n>x;i++)
			x<<=1;
		c = x;
		printf("%llu ",x);
		for(j=0;c!=n;j++)
		{
			if(c-(x>>1) >=n)
				c -= x>>1;
			x>>=1;
		}
		printf("%llu\n",j);
	}
	return 0;
}
