#include<stdio.h>
#include<math.h>
typedef long long int ll;
#define max 1000000
#define root sqrt(max)+1
int tot[max+10];
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
	int test_cases,n;
	scanf("%d",&test_cases);
	while(test_cases--&&scanf("%d",&n))
		printf("%d\n",tot[n]);
	return 0;
}
