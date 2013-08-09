#include<stdio.h>
int main()
{
	long long int n,p,q,i,t=1,num,sum;
	while(scanf("%lld%lld%lld",&n,&p,&q)!=EOF)
	{
		num = n-p+1;
		sum = (num*(2*q + num - 1))/2;
		long double ans = (((sum)*1.0)/(n*num));
		printf("Case %lld: %.4Lf\n",t++,ans);
	}
	return 0;
}
