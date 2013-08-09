#include<stdio.h>
typedef long long int ull;
ull mul(ull n)
{
	ull i,j,k,r=5,temp[5][5];
	ull fib[5][5]={{0,0,1,1,1},{1,0,0,0,0},{0,1,0,0,0},{0,0,0,1,1},{0,0,0,1,0}};
	ull ans[5][5]={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
	while(n--)
	{
		for(i=0;i<r;i++) 
			for(j=0;j<r;j++)
			{
				temp[i][j] = 0;
				for(k=0;k<r;k++)
					temp[i][j]=(temp[i][j]+ans[i][k]*fib[k][j]);
			}
		for(i=0;i<r;i++) 
			for(j=0;j<r;j++) 
				ans[i][j]=temp[i][j];
	}
	for(i=0;i<r;i++) 
	{
		for(j=0;j<r;j++)
			printf("%lld ",ans[i][j]);
		printf("\n");
	}
}
int main()
{
	ull n;
	while(scanf("%lld",&n)&&n)
		mul(n);
	return 0;
}
