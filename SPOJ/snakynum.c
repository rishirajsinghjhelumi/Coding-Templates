#include<stdio.h>
int count=0;
int f(int n,int p,int d)
{
	if(n==1)
	{
		count++;
		return;
	}
	int i;
	if(p==1)
	{
		for(i=0;i<10;i++)
			if(i>d)
				f(n-1,0,i);
	}
	else
	{
		for(i=0;i<10;i++)
			if(i<d)
				f(n-1,1,i);
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<10;i++)
	{
		f(n,1,i);
		f(n,0,i);
	}
	printf("%d\n",n>1?count:10);
	return 0;
}
