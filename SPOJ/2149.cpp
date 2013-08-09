#include<stdio.h>
#include<algorithm>
typedef unsigned long long int ull;
ull a[1000000];
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ull n,i,count = 0;
		scanf("%llu",&n);
		for(i=0;i<n;i++)
			scanf("%*s%llu",&a[i]);
		std::sort(a,a+n);
		for(i=0;i<n;i++)
			count += abs(i+1-a[i]);
		printf("%llu\n",count);
	}
	return 0;
}
