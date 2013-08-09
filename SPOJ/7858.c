#include<stdio.h>
int m=0,n;
int counter(int i,int j)
{
	if(i>n||j>n)
		return;
	if(i==n && j==n)
		m++;
	counter(i+1,j);
	counter(i,j+1);
	counter(i+1,j+1);
}
int main()
{
	scanf("%d",&n);
	counter(1,1);
	printf("%d\n",m);
}
