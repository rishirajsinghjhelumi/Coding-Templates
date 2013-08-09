#include<stdio.h>
#define mod 1000000007
typedef unsigned long long int ull;
ull rec_seq(ull t,ull n,ull *b,ull *c)
{
	if(n<=t)
		return b[n-1];
	n-=t;
	ull ans[9][9]={0};
	ull f[9][9]={0};
	ull i,j,k;
	for(i=0;i<t;i++)
		ans[i][i] = 1;
	for(i=0;i<t;i++)
		f[0][i]=c[i];
	for(i=1;i<t;i++)
		f[i][i-1] = 1;
	while(n)
	{
		if(n&1)
		{
			ull temp[9][9]={0};
			for(i=0;i<t;i++) 
				for(j=0;j<t;j++)
					for(k=0;k<t;k++)
						temp[i][j]=(temp[i][j]+ans[i][k]*f[k][j])%mod;
			for(i=0;i<t;i++) 
				for(j=0;j<t;j++) 
					ans[i][j]=temp[i][j];
		}
		ull temp[9][9]={0};
		for(i=0;i<t;i++) 
			for(j=0;j<t;j++)
				for(k=0;k<t;k++)
					temp[i][j]=(temp[i][j]+f[i][k]*f[k][j])%mod;
		for(i=0;i<t;i++)
			for(j=0;j<t;j++) 
				f[i][j]=temp[i][j];
		n>>=1;

	}
	for(i=0;i<t;i++)
	{
		for(j=0;j<t;j++)
			printf("%llu ",ans[i][j]);
		printf("\n");
	}
	ull sum=0;
	for(i=0;i<t;i++)
		sum = (sum + b[t-i-1]*ans[0][i])%mod;
	return sum;
}
int main()
{
	ull test_cases;
	scanf("%lld",&test_cases);
	while(test_cases--)
	{
		ull m,n,i,s1,s2,sum=0,r,a,a1,x,p,t,k;
		scanf("%llu%llu%llu",&n,&t,&k);
		ull b[t],c[t];
		for(i=0;i<t;i++)
			scanf("%llu",&b[i]);
		for(i=0;i<t;i++)
			scanf("%llu",&c[i]);
		printf("%llu\n",rec_seq(t,n,b,c));
	}
	return 0;
}
