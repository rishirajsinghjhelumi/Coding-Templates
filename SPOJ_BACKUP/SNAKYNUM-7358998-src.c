#include<stdio.h>
typedef long long int ull;
ull c[10] = {0,5,10,-20,-15,21,7,-8,-1,1};
ull b[10] = {0,1,17,81,525, 3105, 18939, 114381, 693129, 4195557};
ull s[9];
ull mul(ull n,ull mod)
{
	ull ans[16][16]={0};
	ull f[16][16]={0};
	ull i,j,k,t = 10,sum=s[8];
	if(n<9)
		return s[n]%mod;
	n-=8;
	for(i=0;i<t;i++)
		ans[i][i] = 1;
	f[0][0]=1;
	for(i=1;i<t;i++)
		f[0][i]=f[1][i]=c[i];
	for(i=2;i<t;i++)
		f[i][i-1] = 1;
	while(n)
	{
		if(n&1)
		{
			ull temp[16][16]={0};
			for(i=0;i<t;i++)
				for(j=0;j<t;j++)
				{
					temp[i][j]=0;
					for(k=0;k<t;k++)
						temp[i][j]=(temp[i][j]+ans[i][k]*f[k][j])%mod;
				}
			for(i=0;i<t;i++)
				for(j=0;j<t;j++)
					ans[i][j]=temp[i][j];
		}
		ull temp[16][16]={0};
		for(i=0;i<t;i++)
			for(j=0;j<t;j++)
			{
				temp[i][j]=0;
				for(k=0;k<t;k++)
					temp[i][j]=(temp[i][j]+f[i][k]*f[k][j])%mod;
			}
		for(i=0;i<t;i++)
			for(j=0;j<t;j++)
				f[i][j]=temp[i][j];
		n>>=1;

	}
	sum=sum*ans[0][0];
	for(i=1;i<t;i++)
		sum = (sum + b[t-i]*ans[0][i] + 1000*mod)%mod;
	return sum;
}
int main()
{
	ull n,i,sum;
	s[0] = 0;
	s[1] = 10;
	s[2] = 91;
	for(i=3;i<9;i++)
		s[i] = s[i-1] + b[i+1];
	ull t;
	scanf("%lld",&t);
	while(t--)
	{
		ull n,mod;
		scanf("%lld%lld",&n,&mod);
		printf("%lld\n",mul(n,mod));
	}
	return 0;
}
