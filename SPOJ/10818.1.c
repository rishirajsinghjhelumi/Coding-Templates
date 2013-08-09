#include<stdio.h>
#include<math.h>
#define max 3200
int p[max]={0},primes[max],k=0,i,j;
int main()
{
	for(i=2;i<=57;i++)
		if(!p[i])
			for(j=2*i;j<max;j=j+i)
				p[j]=1;
	primes[k++]=2;
	for(i=3;i<max;i+=2)
		if(!p[i])
			primes[k++]=i;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i=0,j=0,x;
		//int s=sqrt(n);
		printf("1");
		while(n!=1)
		{
			x = primes[j];
			while(!(n%x))
			{
				n /= x;
				printf(" x %d",x);
			}
			if(++j==k || x*x>=n)
				break;
		}
		if(n!=1)
			printf(" x %d",n);
		printf("\n");
	}
	return 0;
}
