#include<stdio.h>
#define max 100000
#define max2 1000
int a[max+10];
int h[max2+10];
int primes[21]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73};
int p[1000];
int r[max2+10];
int sum_digit(int x)
{
	int s=0;
	while(x)
	{
		s+=x%10;
		x/=10;
	}
	return s;
}
int main()
{
	int i,j,x,c,count=0;
	for(i=0;i<21;i++)
		p[primes[i]] = 1;
	for(i=0;i<max2;i++)
		r[i] = sum_digit(i);
	for(i=0;i<max2;i++)
		h[sum_digit(i)]++;
	for(i=0;i<=max;i++)
	{
		int s = sum_digit(i);
		for(j=0;j<=27;j++)
			if(p[s+j])
				count+=h[j];
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
			if(p[s1+r[j]])
				c1++;
		for(j=0;j<=x2;j++)
			if(p[s2+r[j]])
				c2++;
		printf("%d\n",c2-c1);
	}
	return 0;
}
