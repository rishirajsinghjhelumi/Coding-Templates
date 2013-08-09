#include<stdio.h>
#include<math.h>
#define max 100000
#define root sqrt(max)+1
int i,j,k=0;
char p[max+10];
int primes[10000];
int factors[max+10][17];
int counter[max+10];
int getnum(int n,int m,int x[],int count)
{
	int ans=0;
	int i,j;
	for(i=1;i<(1<<count);i++)
	{
		int b=1,c=0,s,l=1;
		for(j=0;j<count;j++,b<<=1)
			if(i&b)
				c++,l=l*x[j];
		s=c&1?1:-1;
		ans+=s*(m/l);
	}
	return ans;
}
int main()
{
	for(i=2;i<root;i++)
		if(!p[i])
			for(j=i*i;j<=max;j+=i+i)
				p[j]='1';
	primes[k++] = 2;
	for(i=3;i<=max;i+=2)
		if(!p[i])
			primes[k++] = i;
	int num_prime = k;
	k = 66;
	for(i=2;i<=max;i++)
	{
		int n=i,s=sqrt(i),x,j=0;
		while(n!=1)
		{
			x = primes[j];
			int d = 0;
			while(!(n%x))
			{
				d++;
				n /= x;
			}
			if(d)
				factors[i][counter[i]++] = x;
			if(++j==k || x>=s)
				break;
		}
		if(n!=1)
			factors[i][counter[i]++] = n;
	}
	int m,n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",m-getnum(n,m,factors[n],counter[n]));
	}
	return 0;
}
