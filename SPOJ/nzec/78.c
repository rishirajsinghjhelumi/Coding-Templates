#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,k,i,t,s;
		unsigned long long int sum=1;
		scanf("%d%d",&n,&k);
		if(n-k>k)
			t=n-k,s=k;
		else
			t=k,s=n-k;
		n++;
		while(n-->t)
			sum+=sum*n;
		printf("%llu\n",sum);
	}
	return 0;
}
