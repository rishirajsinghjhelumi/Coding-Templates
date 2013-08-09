#include<stdio.h>
#define mod 123456789
typedef long long int ull;
int i, j, k;
ull f(ull n)
{
	ull fib[5][5]={{1,1,-1,1,0},{1,0,0,0,0},{0,1,0,0,0},{0,0,0,1,1},{0,0,0,1,0}};
	ull ans[5][5]={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
	ull temp[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	while(n)
	{
		if(n&1)
		{
			ull temp[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
			for(i=0;i<5;i++) 
				for(j=0;j<5;j++)
					for(k=0;k<5;k++)
						temp[i][j]=(temp[i][j]+ans[i][k]*fib[k][j]+mod)%mod;
			for(i=0;i<5;i++) 
				for(j=0;j<5;j++) 
					ans[i][j]=temp[i][j];
		}
		ull temp[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
		for(i=0;i<5;i++) 
			for(j=0;j<5;j++) 
				for(k=0;k<5;k++)
					temp[i][j]=(temp[i][j]+fib[i][k]*fib[k][j]+mod)%mod;
		for(i=0;i<5;i++)
			for(j=0;j<5;j++) 
				fib[i][j]=temp[i][j];
		n>>=1;

	}
	return (ans[0][0]*12+ans[0][1]*8+ans[0][2]*3+ans[0][4]+mod)%mod;
}
int main()
{
	ull n,t,a[4]={0,3,8,12};
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n>3)
			printf("%lld\n",f(n-3));
		else
			printf("%lld\n",a[n]);
	}
	return 0;
}
