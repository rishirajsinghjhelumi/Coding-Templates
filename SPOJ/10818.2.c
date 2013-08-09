#include<stdio.h>
#include<math.h>
#define max 3200
#define max2 100000
int p[max],k=0,i,j,primes[max];
int a[max2+10][20];
int ind[max2+10];
void gen_fac();
void gen_prime();
int main()
{
	gen_prime();
	gen_fac();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<=max2)
		{
			printf("1");
			j = ind[n];
			for(i=0;i<j;i++)
				printf(" x %d",a[n][i]);
			printf("\n");
			continue;
		}
		int i=0,j=0,s=sqrt(n),x;
		printf("1");
		while(n!=1)
		{
			x = primes[j];
			while(!(n%x))
			{
				n /= x;
				printf(" x %d",x);
			}
			if(++j==k || x>=s)
				break;
		}
		if(n!=1)
			printf(" x %d",n);
		printf("\n");
	}
	return 0;
}
void gen_fac()
{
	a[2][0]=2;
	ind[2]=1;
	for(i=3;i<=max2;i++)
	{
		int d,n=i,j=0,x,ans=1;
		while(n!=1)
		{
			x = primes[j];
			while(!(n%x))
			{
				a[i][ind[i]++]=x;
				n/=x;
			}   
			if(++j==66 || x*x>=n)
				break;
		}   
		if(n!=1)
			a[i][ind[i]++]=n;
	} 
}
void gen_prime()
{
	for(i=2;i<=57;i++)
		if(!p[i])
			for(j=2*i;j<=max;j=j+i)
				p[j]=1;
	primes[k++]=2;
	for(i=3;i<max;i+=2)
		if(!p[i])
			primes[k++]=i;
}
