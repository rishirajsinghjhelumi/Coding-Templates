#include<stdio.h>
typedef unsigned long long int ull;
int main()
{
	ull a[100],i,j,ans[100],k=2;
	a[1] = 1;
	for(i=2;i<=30;i++)
		a[i] = ((2*i-1)*(2*i-2)*a[i-1])/(i*(i-1));
	ans[1]=1;
	ans[2]=1;
	ans[3]=1;
	for(i=4;i<=62;i+=2)
	{
		ans[i] = ans[i-1] + a[k++];
		ans[i+1] = ans[i];
	}
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ull n,x=2,bit=1;
		scanf("%llu",&n);
		while(1)
		{
			if(n==x)
				break;
			x<<=1;
			bit++;
		}
		printf("%llu\n",ans[bit]);
	}
	return 0;
}
