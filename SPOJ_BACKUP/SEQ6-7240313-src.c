#include<stdio.h>
#include<math.h>
#define max 3200
typedef unsigned long long int ull;
int p[max]={0},primes[max],k=0,i,j;
int main()
{
	for(i=2;i<=57;i++)
		if(!p[i])
			for(j=2*i;j<max;j=j+i)
				p[j]=1;
	for(i=3;i<max;i+=2)
		if(!p[i])
			primes[k++]=i;
	ull n;
	while(scanf("%llu",&n) && n)
	{
		ull i=0,j=0,s=sqrt(n),x,count=1,c=1;
		while(!(n%2))
			n>>=1;
		while(n!=1)
		{
			c=1;
			x = primes[j];
			while(!(n%x))
			{
				n /= x;
				c++;
			}
			count *=c;
			if(j+1==k || x>=s)
				break;
			j++;
		}
		if(n!=1)
			count<<=1;
		printf("%llu\n",count<<1);
	}
	return 0;
}
