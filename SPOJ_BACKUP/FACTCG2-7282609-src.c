#include<stdio.h>
#include<math.h>
#define max 3200
#define max2 100000
#define max3 10000000
#define mm (max3-1)>>1
#define xx (floor(sqrt(max3)-1))/2
int p[mm];
int primes[2010000];
int k=0,i,j;
int a[max2+10][20];
int ind[max2+10];
void gen_fac();
void gen_prime();
void gen_prime2();
void print_n(int n);
void printer(int n);
int main()
{
	gen_prime2();
	//gen_fac();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("1");
		//if(n<=max2)
		//	print_n(n);
		//else
		if(n&1 && !p[(n-1)>>1] && n!=1)
			printf(" x %d",n);
		else
			printer(n);
		printf("\n");
	}
	return 0;
}
void printer(int n)
{
	int i=0,j=0,x;
	while(n!=1)
	{
		x = primes[j];
		while(!(n%x))
		{
			n /= x;
			printf(" x %d",x);
			//if(n<=max2)
			//{
			//	print_n(n);
			//	return;
			//}
		}
		if(p[(n-1)/2]==0&&n!=1)
		{
			printf(" x %d",n);
			return;
		}
		if(++j==k || x*x>=n)
			break;
	}
	if(n!=1)
		printf(" x %d",n);
}
void print_n(int n)
{
	j = ind[n];
	for(i=0;i<j;i++)
		printf(" x %d",a[n][i]);
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
void gen_prime2()
{
	for(i=1;i<=xx;i++)
		if(!p[i])
			for(j=((i+1)*i)<<1;j<=mm;j+=(i<<1)+1)
				p[j]=1;
	primes[k++] = 2;
	for(i=1;i<=mm;i++)
		if(!p[i])
			primes[k++] = (i<<1)+1;
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
