#include<stdio.h>
#define max 100000
#define max2 1000
#define cons 100
int a[max+10];
int h[max+10];
int r[max+10];
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
		x = sum_digit2(i);
		count+=h[1-x+cons];
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
		int s1=sum_digit2(A/max2),s2=sum_digit2(B/max2);
		for(j=0;j<=x1;j++)
			if(s1+r[j]==1)
				c1++;
		for(j=0;j<=x2;j++)
			if(s2+r[j]==1)
				c2++;
		printf("%d\n",c2-c1);
	}
	return 0;
}
