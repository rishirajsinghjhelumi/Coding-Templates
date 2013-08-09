#include<stdio.h>
typedef unsigned long long int ull;
int main()
{
	ull a[1010],i,n;
	a[0]=1;
	for(i=1;i<1001;i++)
		a[i] = ((2*(2*i-1)*a[i-1])/(i+1))%1000000;
	while(scanf("%llu",&n) && (n))
		printf("%llu\n",a[n]);
	return 0;
}
