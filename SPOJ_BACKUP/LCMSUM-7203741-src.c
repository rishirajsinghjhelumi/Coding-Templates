#include<stdio.h>
typedef long long int ll;
#define max 1000000
ll tot[max+10],a[max+10];
int main()
{
	ll i,j,k;
	for(i=1;i<=max;i++)
		tot[i]=i;
	for(i=4;i<=max;i+=2)
		tot[i] -= tot[i]>>1;
	for(i=3;i<=max/2;i+=2)
		if(tot[i] == i)
			for(j=i+i;j<=max;j+=i)
				tot[j] -= tot[j] / i;
	tot[2] = 1;
	for(i=3;i<=max;i+=2)
		if(tot[i] == i)
			tot[i]--;
	for(i=1;i<=max;i++) 
		for (j=i;j<=max;j+=i) 
			a[j] += i*tot[i];
	ll test_cases,n;
	scanf("%lld",&test_cases);
	while(test_cases-- && scanf("%lld",&n))
		printf("%lld\n",((1+a[n])*n)>>1);
	return 0;
}
