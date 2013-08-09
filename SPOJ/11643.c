#include<stdio.h>
long long int count=0,mod=1000000007;
int n,i,j;
char a[1000][1000];
int counter(int i,int j);
int main()
{
	scanf("%d%*c",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%c",&a[i][j]);
		scanf("%*c");
	}
	counter(0,0);
	printf("%lld\n",count);
	return 0;
}
int counter(int i,int j)
{
	if(i==n-1 && j==n-1)
	{
		count = (count+1)%mod;
		return;
	}
	if(a[i][j] == '#')
		return;
	if(j+1<n)
		counter(i,j+1);
	if(i+1<n)
		counter(i+1,j);
}
