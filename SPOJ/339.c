#include<stdio.h>
#define mod 1000000000
typedef unsigned long long int ull;
ull rec_seq(ull t,ull n,ull *b,ull *c)
{
	ull ans[10][10]={0};
	ull f[10][10]={0};
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
			ull temp[10][10]={0};
			for(i=0;i<t;i++) 
				for(j=0;j<t;j++)
					for(k=0;k<t;k++)
						temp[i][j]=(temp[i][j]+ans[i][k]*f[k][j])%mod;
			for(i=0;i<t;i++) 
				for(j=0;j<t;j++) 
					ans[i][j]=temp[i][j];
		}
		ull temp[10][10]={0};
		for(i=0;i<t;i++) 
			for(j=0;j<t;j++) 
				for(k=0;k<t;k++)
					temp[i][j]=(temp[i][j]+f[i][k]*f[k][j])%mod;
		for(i=0;i<t;i++)
			for(j=0;j<t;j++) 
				f[i][j]=temp[i][j];
		n>>=1;

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
		ull t;
		scanf("%llu",&t);
		ull b[t],c[t],m,n,i,s1;
		for(i=0;i<t;i++)
			scanf("%llu",&b[i]);
		for(i=0;i<t;i++)
			scanf("%llu",&c[i]);
		scanf("%llu",&n);
		s1 = n-1>t?rec_seq(t,n-t,b,c):b[n-1];
		printf("%llu\n",(s1)%mod);
	}
	return 0;
}
