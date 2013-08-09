#include<stdio.h>
typedef long long int ull;
ull c[9] = {5,10,-20,-15,21,7,-8,-1,1};
ull b[9] = {1,17,81,525, 3105, 18939, 114381, 693129, 4195557};
ull s[9];
ull mul(ull n,ull mod)
{
	ull i,j,k,r=10,temp[10][10];
	ull fib[10][10] = {0};
	ull ans[10][10] = {0};
	if(n<9)
		return s[n]%mod;
	n=n-8;
	for(i=0;i<r;i++)
		ans[i][i] = 1;
	fib[0][0] = 1;
	for(i=1;i<r;i++)
		fib[0][i] = fib[1][i] = c[i];
	for(i=2;i<r;i++)
		fib[i][i-1] = 1;
	while(n)
	{
		if(n&1)
		{
			for(i=0;i<r;i++) 
				for(j=0;j<r;j++)
				{
					temp[i][j] = 0;
					for(k=0;k<r;k++)
						temp[i][j]=(temp[i][j]+ans[i][k]*fib[k][j])%mod;
				}
			for(i=0;i<r;i++) 
				for(j=0;j<r;j++) 
					ans[i][j]=temp[i][j];
		}
		for(i=0;i<r;i++) 
			for(j=0;j<r;j++)
			{
				temp[i][j]=0;
				for(k=0;k<r;k++)
					temp[i][j]=(temp[i][j]+fib[i][k]*fib[k][j])%mod;
			}
		for(i=0;i<r;i++)
			for(j=0;j<r;j++) 
				fib[i][j]=temp[i][j];
		n>>=1;
	}
	ull sum = (s[8]*ans[0][0])%mod;
	for(i=1;i<r;i++)
		sum = (sum + b[r-i-1]*ans[0][i] + mod)%mod;
	return sum;
}
int main()
{
	ull n,i,sum;
	s[0] = 0;
	s[1] = 10;
	s[2] = 91;
	for(i=3;i<9;i++)
		s[i] = s[i-1] + b[i];
	while(scanf("%lld",&n)&&n)
	{
		ull mod = 100000000;
		mod*=mod;
		mod*=10;
		printf("%lld\n",mul(n,mod));
	}
	return 0;
}
