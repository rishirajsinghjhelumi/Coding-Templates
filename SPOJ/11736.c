#include<stdio.h>
#include<math.h>
#define max 10010
typedef long long int ll;
ll p[max]={0},k=0,i,j,p_k,m;
ll primes[100]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
ll pri[1300];
ll fact[1300];
ll count[1300];
int main()
{
	for(i=2;i<=101;i++)
		if(!p[i])
		{
			for(j=2*i;j<max;j=j+i)
				p[j]=1;
		}
	pri[k++] = 2;
	for(i=3;i<max;i+=2)
		if(!p[i])
			pri[k++]=i;
	p_k = k;
	k = 26;
	int n,l=0;
	while(scanf("%d",&n)!=EOF)
	{
		l = 0;
		for(i=0;pri[i]<=n;i++)
		{
			ll x = n,a=pri[i],c=0;
			while((x/a)!=0)
			{
				c += x/a;
				a *= pri[i];
			}
			fact[l] = pri[i];
			count[l++] = c;
		}
		for(i=0;i<l-1;i++)
			printf("%lld^%lld * ",fact[i],count[i]);
		printf("%lld^%lld\n",fact[i],count[i]);
	}
	return 0;
}
