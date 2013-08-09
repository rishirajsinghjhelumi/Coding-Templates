#include<stdio.h>
#define max 100000
#define max2 10000
#define cons 100
int a[max+10];
int h[max+10];
int r[max+10];
int primes[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int p[1000];
int sum_digit(int x)
{
	int s=0,l=0;
	while(x)
	{
		s += (++l)%2?-x%10:x%10;
		x/=10;
	}
	return s;
}
int sum_digit2(int x)
{
	int s=0,l=0;
	while(x)
	{
		s += (l++)%2?-x%10:x%10;
		x/=10;
	}
	return s;
}
int main()
{
	int i,count=0,j,x;
	for(i=0;i<max2;i++)
	{
		r[i] = sum_digit(i);
		h[r[i]+cons]++;
	}
	for(i=0;i<=max;i++)
	{
		x = sum_digit(i);
		for(j=0;j<11;j++)
			count+=h[primes[j]-x+cons];
		a[i] = count;
	}
	int t,A,B;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&A,&B);
		A--;
		int c1 = A>=max2?a[A/max2-1]:0;
		int c2 = B>=max2?a[B/max2-1]:0;
		int x1 = A%max2,x2=B%max2;
		int s1=sum_digit(A/max2),s2=sum_digit(B/max2);
		for(j=0;j<=x1;j++)
		{
			for(i=0;i<11;i++)
				if(s1+r[j]==primes[i])
					c1++;
		}
		for(j=0;j<=x2;j++)
		{
			for(i=0;i<11;i++)
				if(s2+r[j]==primes[i])
					c2++;
		}
		printf("%d\n",c2-c1);
	}
	return 0;
}
