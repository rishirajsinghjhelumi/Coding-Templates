#include<stdio.h>
#define mod 98765431
typedef long long int LL;
LL c[100000];
int main()
{
	LL i,a[50]={0},j,n,t,sum=0,b=1,p_sum;
	scanf("%lld%lld",&n,&t);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&c[i]);
		sum = (sum + c[i])%mod;
	}
	for(i=0;i<49;i++)
		a[i+1] = ( (a[i]*a[i])%mod + (n-1)*( ((a[i]-1) * (a[i]-1))%mod ) )%mod;
	for(i=0;t>=b;i++,b<<=1)
		if(t&b)
		{
			p_sum = 0;
			if(i)
			{
				for(j=0;j<n;j++)
				{
					c[j] = ( (a[i]*c[j])%mod + ((a[i]-1)*(sum-c[j]+mod))%mod + mod)%mod;
					p_sum = (p_sum + c[j])%mod;
				} 
				sum = p_sum;
			}
			else
			{
				for(j=0;j<n;j++)
				{
					c[j]=(sum-c[j]+mod)%mod;
					p_sum = (p_sum+c[j])%mod;
				}
				sum = p_sum;
			}
		}
	for(i=0;i<n;i++)
		printf("%lld\n",c[i]);
	return 0;
}
