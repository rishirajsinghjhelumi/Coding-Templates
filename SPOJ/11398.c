#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int x,ans=0;
		long long int n;
		scanf("%lld",&n);
		x=n%4;
		if(x==0 || x==1)
			ans=1;
		printf("%s\n",ans==1?"YES":"NO");
	}
	return 0;
}
