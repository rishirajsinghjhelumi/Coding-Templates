#include<stdio.h>
typedef long long int ll;
#define max 100000
#define root 3300
ll tot[max+10];
int main()
{
	ll i,j,k;
	for(i=1;i<=max;i++)
		tot[i]=i;
	for(i=4;i<=max;i+=2)
		tot[i] -= tot[i]>>1;
	for(i=3;i<=max>>1;i+=2)
		if(tot[i] == i)
			for(j=i+i;j<=max;j+=i)
				tot[j] -= tot[j] / i;
	tot[2] = 1;
	for(i=3;i<=max;i+=2)
		if(tot[i] == i)
			tot[i] = i-1;
	return 0;
}
