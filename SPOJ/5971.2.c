#include<stdio.h>
long long int f(int n,int prime[],int k);
int main()
{
	int i,p[1000]={0},j,prime[1000],k=0;
	for(i=2;i<1000;i++)
		if(p[i]==0)
		{
			prime[k++] = i;
			for(j=2*i;j<1000;j=j+i)
				p[j] = 1;
		}
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int a;
		scanf("%d",&a);
		printf("%lld\n",(a*(f(a,prime,k)+1)/2)%1000000007);
	}
	return 0;
}
long long int f(int n,int prime[],int k)
{
	int res=1,x,i;
	for(i=0; i < k && 1 < n && prime[i] < n; i++)
	{
		x = prime[i];
		while(n % prime[i]==0)
		{
			x *= prime[i]*prime[i];
			n /= prime[i];
		}
		res *= ((x+1)/(prime[i]+1))%1000000007;
	}
	if(n > 1)
		res*=(n*(n-1)+1)%1000000007;
	return res; 
}
