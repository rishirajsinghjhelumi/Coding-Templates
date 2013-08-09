#include<stdio.h>
int p[20];
int count = 0;
int f(int n,int d)
{
	int i;
	if(n==1)
	{
		count++;
		return;
	}
	for(i=1;i<10;i++)
		if(p[d+i])
			f(n-1,i);
}
int main()
{
	p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[19]=1;
	int n,i;
	scanf("%d",&n);
	for(i=1;i<10;i++)
		f(n,i);
	printf("%d\n",count);
	return 0;
}
