#include<stdio.h>
typedef unsigned long long int ull;
ull temp[30][30];
ull rec_seq(ull t,ull n,ull mod)
{
	ull ans[30][30]={0};
	ull f[30][30]={0};
	ull i,j,k;
	for(i=0;i<t;i++)
		ans[i][i] = 1;
	for(i=0;i<t;i++)
		f[0][i]=1;
	for(i=1;i<t;i++)
		f[i][i-1] = 1;
	while(n)
	{
		if(n&1)
		{
			for(i=0;i<t;i++) 
				for(j=0;j<t;j++)
				{
					temp[i][j] = 0;
					for(k=0;k<t;k++)
						temp[i][j]=(temp[i][j]+ans[i][k]*f[k][j])%mod;
				}
			for(i=0;i<t;i++) 
				for(j=0;j<t;j++) 
					ans[i][j]=temp[i][j];
		}
		for(i=0;i<t;i++) 
			for(j=0;j<t;j++) 
			{
				temp[i][j] = 0;
				for(k=0;k<t;k++)
					temp[i][j]=(temp[i][j]+f[i][k]*f[k][j])%mod;
			}
		for(i=0;i<t;i++)
			for(j=0;j<t;j++) 
				f[i][j]=temp[i][j];
		n>>=1;

	}
	ull sum=0;
	for(i=0;i<t;i++)
		sum = (sum + (t-i-1)*ans[0][i])%mod;
	return sum;
}
int main()
{
	ull test_cases;
	scanf("%llu",&test_cases);
	while(test_cases--)
	{
		ull m,n,i,s1,t,k;
		scanf("%llu%llu%llu",&t,&k,&n);
		ull mod=1;
		for(i=0;i<k;i++)
			mod*=10;
		s1 = n-1>t?rec_seq(t,n-t+1,mod):n-1;
		printf("%llu\n",(s1)%mod);
	}
	return 0;
}
