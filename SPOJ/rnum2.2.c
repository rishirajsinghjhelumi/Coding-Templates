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
	scanf("%d",&n);
	for(i=1;i<10;i++)
		f(n,i);
	printf("%d\n",count);
	return 0;
}
