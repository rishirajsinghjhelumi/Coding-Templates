#include<stdio.h>
int cuts=0,p_len,max=0,done=0;
int cutter(char a[],int lower,int upper,int cuts);
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
		max=99999;
		if(a[0]=='0')
			max=0;
		else
		{
			cutter(a,0,n-1,0);
		}
		printf("%d\n",max);
		cuts=done=0;
		max=99999;
	}
	return 0;
}
int cutter(char a[],int lower,int upper,int cuts)
{
	printf("u==%d l==%d p_len==%d u-l+1==%d cuts==%d max==%d\n",upper,lower,p_len,upper-lower+1,cuts,max);
	if(upper==lower)
	{
		if(cuts<max && done==0)
		{
			done=1;
			max=cuts;
		}
	}
	if(lower>=upper)
		return;
	if(a[lower] == '1')
	{
		cutter(a,lower,(lower+upper)/2,cuts+1);
		cutter(a,(lower+upper)/2+1,upper,cuts+1);
	}
	else
		return;
}
