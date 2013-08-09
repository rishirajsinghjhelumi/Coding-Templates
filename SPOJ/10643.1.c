#include<stdio.h>
int mod = 1000000007;
int f(int n , int k);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		printf("%d\n",f(n,k)%mod);
	}
	return 0;
}
int f(int n , int k)
{
	if(n<0||k<0)
		return 0;
	if(n>0 && k==0)
		return 0;
	if(n==0 && k>=0)
		return 1;
	return (f(n,k-1)+ f(n-k,k))%mod;
}
