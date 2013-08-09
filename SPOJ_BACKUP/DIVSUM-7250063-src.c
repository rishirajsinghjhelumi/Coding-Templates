#include<stdio.h>
#include<math.h>
typedef unsigned long long int ll;
#define max 710
#define root sqrt(max)+1
ll i,j,k=0;
char p[max];
ll primes[max];
int main()
{
	for(i=2;i<root;i++)
		if(!p[i])
			for(j=i+i;j<max;j+=i)
				p[j]='1';
	primes[k++] = 2;
	for(i=3;i<max;i+=2)
		if(!p[i])
			primes[k++] = i;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,j=0,i,l=0,d;
		scanf("%llu",&n);
		ll s = sqrt(n),sum = 1,x,m=n;
		while(n!=1)
		{
			x = primes[j];
			d = 0;
			while(!(n%x))
			{
				n /= x;
				d++;
			}
			if(d)
				sum = sum * ((pow(x,d+1)-1)/(x-1));
			if(j+1==k || x>=s)
				break;
			j++;
		}
		if(n!=1)
			sum = sum * (n+1);
		printf("%llu\n",sum-m);
	}
	return 0;
}
