#include<stdio.h>
typedef unsigned long long int ull;
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ull n,k,ans=1,i;
		scanf("%llu%llu",&n,&k);
		n--;
		k--;
		if(k>n>>1)
			k=n-k;
		for(i=1;i<=k;i++)
			ans = ans* (n+1-i)/i;
		printf("%llu\n",ans);
	}
	return 0;
}
