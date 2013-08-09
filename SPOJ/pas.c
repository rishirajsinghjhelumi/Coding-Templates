#include<stdio.h>
#define max 100000
#define mod 500000002
int ncr[max+10];
void pastri(int *a,int *b,int i)
{
	int x = i&1?i/2+1:i/2,j;
	a[0] = 1;
	for(j=1;j<x;j++)
		a[j] = (b[j-1] + b[j])%mod;
	if(!(i&1))
		a[x] = a[x-1];
}
int main()
{
	int a[100010];
	int b[100010];
	int i,j,x,c=0;
	b[0] = 1;
	for(i=2;i<=20000;i++)
	{
		if(i&1)
			pastri(b,a,i);
		else
			pastri(a,b,i);
	}
	return 0;
}
