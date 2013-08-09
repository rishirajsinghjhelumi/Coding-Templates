#include<stdio.h>
int min = 99999;
int a[100],d[100],b[100],n,i;
int counter(int x,int energy,int path);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d%d",&a[i],&d[i],&b[i]);
		counter(0,0,0);
		printf("%d\n",min);
		min = 99999;
	}
	return 0;
}
int counter(int x,int energy,int path)
{
	if(x==n)
	{
		if(energy<min)
			min = energy;
		return;
	}
	if(path==0)
	{
		counter(x+1,energy+a[x],1);
		counter(x+1,energy+d[x],2);
		counter(x+1,energy+b[x],3);
	}
	else if(path==1)
	{
		counter(x+1,energy+d[x],2);
		counter(x+1,energy+b[x],3);
	}
	else if(path==2)
	{
		counter(x+1,energy+a[x],1);
		counter(x+1,energy+b[x],3);
	}
	else if(path==3)
	{
		counter(x+1,energy+a[x],1);
		counter(x+1,energy+d[x],2);
	}
	return;
}
