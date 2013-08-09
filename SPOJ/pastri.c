#include<stdio.h>
typedef unsigned long long int ull;
ull a[1000000],b[1000000];
int main()
{
	ull i,j,x;
	a[0] = 1;
	for(i=1;i<=10;i++)
	{
		b[0] = b[i] = 1;
		x = i&1?(i+1)/2:(i+2)/2;
		for(j=1;j<x;j++)
			b[j] = (a[j-1] + a[j])%1000000;
		b[x] = b[x-1];
		for(j=0;j<x;j++)
		{
			printf("%llu ",b[j]);
			a[j] = b[j];
		}
		printf("\n");//754901378 
	}
	return 0;
}
