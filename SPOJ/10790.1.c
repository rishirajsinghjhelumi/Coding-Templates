#include<stdio.h>
#define max 100000
#define max2 1000
int a[max+10];
int h[max2+10];
int primes[21]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73};
int p[100];
int main()
{
	int i,j,x,c,count=0,m;
	for(i=0;i<21;i++)
		p[primes[i]] = 1;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		int x=i,s=0;
		while(x)
		{
			s+=x%10;
			x/=10;
		}
		if(p[s])
			count++;
	}
	printf("%d\n",count);
	return 0;
}
