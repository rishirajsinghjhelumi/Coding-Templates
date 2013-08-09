#include<stdio.h>
int f(int n,int m,int a,int b)
{
	if(n==1)
		return a;
	if(n==2)
		return b;
	return f(n-1,m,a,b)%m+f(n-2,m,a,b)%m;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,n,m,ans=0,i,c;
		scanf("%d%d%d%d",&a,&b,&n,&m);
		printf("%d\n",(f(n+2,m,a,b)-b)%m);
	}
	return 0;
}
