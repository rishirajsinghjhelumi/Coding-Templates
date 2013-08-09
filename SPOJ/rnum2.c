#include<stdio.h>
#define mod 1000000007
int p[20];
int a[100000][10],count=0;
int f(int n,int d)
{
	int i;
	if(n==1)
	{
		count++;
		return;
	}
	if(d==1)
		return f(n-1,1)+f(n-1,2)+f(n-1,4)+f(n-1,6);
	else if(d==2)
		return f(n-1,1)+f(n-1,3)+f(n-1,5)+f(n-1,9);
	else if(d==3)
		return f(n-1,2)+f(n-1,4)+f(n-1,8);
	else if(d==4)
		return f(n-1,1)+f(n-1,3)+f(n-1,7)+f(n-1,9);
	else if(d==5)
		return f(n-1,2)+f(n-1,6)+f(n-1,8);
	else if(d==6)
		return f(n-1,1)+f(n-1,5)+f(n-1,7);
	else if(d==7)
		return f(n-1,4)+f(n-1,6);
	else if(d==8)
		return f(n-1,3)+f(n-1,5)+f(n-1,9);
	else if(d==9)
		return f(n-1,2)+f(n-1,4)+f(n-1,8);
}
int main()
{
	p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[19]=1;
	int n,i,d;
	for(i=1;i<10;i++)
		a[1][i] = 1;
	for(n=2;n<15;n++)
	{
		int sum = 0;
		for(d=1;d<10;d++)
		{
			for(i=1;i<10;i++)
				if(p[i+d])
					a[n][d] += a[n-1][i];
			a[n][d]%=mod;
			printf("%d ",a[n][d]);
			sum += a[n][d];
		}
		printf("sum==%d\n",sum);
	}
	return 0;
}
