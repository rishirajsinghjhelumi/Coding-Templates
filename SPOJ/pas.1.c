#include<stdio.h>
#define max 100000
#define mod 500000002
int a[1010][1010];
int ncr[max+10];
int main()
{
	int i,j,x,c=0;
	a[1][0] = 1;
	for(i=2;i<=20;i++)
	{
		x = i&1?i/2+1:i/2;
		a[i][0] = 1;
		printf("%d ",a[i][0]);
		for(j=1;j<x;j++)
		{
			a[i][j] = (a[i-1][j-1] + a[i-1][j])%mod;
			printf("%d ",a[i][j]);
		}
		if(!(i&1))
		{
			a[i][x] = a[i][x-1];
			printf("%d ",a[i][x]);
		}
		printf("\n");
	}
	return 0;
}
