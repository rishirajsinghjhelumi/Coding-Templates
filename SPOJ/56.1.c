#include<stdio.h>
int cuts=0,p_len,max=0;
int cutter(char a[],int lower,int upper);
int main()
{
	int t=10;
	while(t--)
	{
		int n,i,j;
		char a[100000];
		scanf("%d",&n);
		scanf("%s",a);
		p_len = n;
		max=1;
		if(a[0]=='0')
			max=0;
		else
		{
			cutter(a,0,n-1);
		}
		printf("%d\n",max);
		cuts=0;
	}
	return 0;
}
int cutter(char a[],int lower,int upper)
{
	//printf("u==%d l==%d p_len==%d u-l+1==%d cuts==%d max==%d\n",upper,lower,p_len,upper-lower+1,cuts,max);
	if(upper -  lower + 1 < p_len)
	{
		max = cuts;
		p_len = upper - lower + 1;
	}
	if(lower>=upper)
		return;
	if(a[lower] == '1')
	{
		cuts++;
		cutter(a,lower,(lower+upper)/2);
		cutter(a,(lower+upper)/2+1,upper);
	}
	else
		return;
}
