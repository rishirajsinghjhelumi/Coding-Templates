#include<stdio.h>
typedef unsigned long long int ull;
ull mod;
ull temp[16][16];
ull mulmod(ull a,ull b)
{
	if(a<1000000000 && b<1000000000)
		return (a*b)%mod;
	ull x = 0,y=a%mod;
	while(b > 0)
	{
		if(b&1)
			x = (x+y)%mod;
		y = (y<<1)%mod;
		b >>=1;
	}
	return x;
}
ull rec_seq(ull t,ull n,ull *b,ull *c,ull sum)
{
	ull ans[16][16]={0};
	ull f[16][16]={0};
	ull i,j,k;
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
			for(i=0;i<t;i++) 
				for(j=0;j<t;j++)
				{
					temp[i][j]=0;
					for(k=0;k<t;k++)
						temp[i][j]=(temp[i][j]+mulmod(ans[i][k],f[k][j]))%mod;
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
					temp[i][j]=(temp[i][j]+mulmod(f[i][k],f[k][j]))%mod;
			}
		for(i=0;i<t;i++)
			for(j=0;j<t;j++) 
				f[i][j]=temp[i][j];
		n>>=1;

	}
	sum=sum*ans[0][0];
	for(i=1;i<t;i++)
		sum = (sum + b[t-i]*ans[0][i])%mod;
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
		t+=1;
		ull b[t],c[t],m,n,i,s1,s2,sum=0,s[t];
		for(i=1;i<t;i++)
		{
			scanf("%llu",&b[i]);
			sum+=b[i];
			s[i]=sum;
		}
		s[0]=0;
		for(i=1;i<t;i++)
			scanf("%llu",&c[i]);
		scanf("%llu%llu%llu",&m,&n,&mod);
		s1 = n>t-1?rec_seq(t,n-t+1,b,c,sum):s[n];
		m--;
		s2 = m>t-1?rec_seq(t,m-t+1,b,c,sum):s[m];
		printf("%llu\n",(s1-s2+mod)%mod);
	}
	return 0;
}
