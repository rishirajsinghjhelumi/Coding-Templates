#include<stdio.h>
int mod = 1000000007;
int f(int n , int k);
typedef unsigned long long int ull;
ull a[1010][1010];
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ull n,k,i,j;
		scanf("%llu%llu",&n,&k);
		for(i=1;i<=n;i++)
			for(j=1;j<=k;j++)
			{
				if(j>i)
					a[i][j] = 0;
				if(i==j)
					a[i][j] = 1;
			}
		for(i=n;i>=1;i--)
		{
			for(j=k;j>=1;j--)
			{
				if(j+1<=k)
					a[i][j] = a[i][j+1]+a[i-j][j];
			}
		}
	}
	return 0;
}
int f(int n , int k)
{
	if(k>n)
		return 0;
	if(k==n)
		return 1;
	return (f(n,k+1)+ f(n-k,k))%mod;
}
