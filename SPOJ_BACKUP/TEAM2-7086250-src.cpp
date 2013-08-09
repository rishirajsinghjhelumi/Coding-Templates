#include<stdio.h>
#include<algorithm>
int main()
{
	long long int a[4],t=1;
	while(scanf("%lld%lld%lld%lld",&a[0],&a[1],&a[2],&a[3])!=EOF)
	{
		std::sort(a,a+4);
		printf("Case %lld: %lld\n",t++,a[2] + a[3]);
	}
	return 0;
}
