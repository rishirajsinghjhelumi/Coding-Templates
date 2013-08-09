#include<stdio.h>
#define mod 4294967296
#define m1 19
#define m2 55
#define m3 37
typedef long long int lld;
lld dp[20][55][37][20][20];
lld pow9[20];
lld pow2[20]= {0 , 0 , 9 , 171 , 2439 , 30951 , 368559 , 4217031 , 46953279U , 512579511U , 1218248303U , 2784365543U , 3390140191U , 2798325783U , 1458643151U , 3498166087U , 3906748799U , 4206415223U , 3192404271U , 4200858279U };
lld input()
{
	char c = getchar_unlocked();
	lld x=0;
	while(c>=48 && c<=57)
	{
		x = (x<<3)+(x<<1)+c-48;
		c = getchar_unlocked();
	}
	return x;
}
int main()
{
	int a,b,c,d,len;
	dp[0][0][0][0][0] = 1;
	for(len=1;len<m1;len++)
		for(a=0;a<m2;a++)
			for(b=0;b<m3;b++)
				for(c=0;c<m1;c++)
					for(d=0;d<m1;d++)
						{
							lld count = dp[len-1][a][b][c][d];
							if(a>=1)
								count += dp[len-1][a-1][b][c][d];
							if(b>=1)
								count += dp[len-1][a][b-1][c][d];
							if(a>=2)
								count += dp[len-1][a-2][b][c][d];
							if(c>=1)
								count += dp[len-1][a][b][c-1][d];
							if(a>=1 && b>=1)
								count += dp[len-1][a-1][b-1][c][d];
							if(d>=1)
								count += dp[len-1][a][b][c][d-1];
							if(a>=3)
								count += dp[len-1][a-3][b][c][d];
							if(b>=2)
								count += dp[len-1][a][b-2][c][d];
							dp[len][a][b][c][d] = count % mod;
						}
	lld t,v,l;
	pow9[0] = 1;
	for(t=1;t<20;t++)
		pow9[t] = (pow9[t-1] * 9) % mod;
	t = input();
	int i,j,k,m;
	while(t--)
	{
		l = input();
		v = input();
		int num = (l+1)/2;
		int den = l/2;
		if(!v)
		{
			if(l==1)
				printf("1\n");
			else
				printf("%lld\n",(pow9[den] * pow2[num]) % mod);
			continue;
		}
		int f[4] = {2,3,5,7};
		int factor[4]={0,0,0,0};
		for(i=0;i<4;i++)
		{
			int x = f[i];
			int count = 0;
			while(v % x == 0)
			{
				v /= x;
				count++;
			}
			factor[i] = count;
		}
		if(v!=1)
		{
			printf("0\n");
			continue;
		}
		lld ans = 0;
		int a2=factor[0],a3=factor[1],a5=factor[2],a7=factor[3];
		for(a=a2;a<m2 && a-a2<m2 && dp[num][a][0][0][0] && dp[den][a-a2][0][0][0];a++)
		{
			for(b=a3;b<m3 && b-a3<m3 && dp[num][a][b][0][0] && dp[den][a-a2][b-a3][0][0];b++)
				for(c=a5;c<m1 && c-a5<m1 && dp[num][a][b][c][0] && dp[den][a-a2][b-a3][c-a5][0];c++)
					for(d=a7;d<m1 && d-a7<m1 && dp[num][a][b][c][d] && dp[den][a-a2][b-a3][c-a5][d-a7];d++)
					{
						ans = (ans + dp[num][a][b][c][d] * dp[den][a-a2][b-a3][c-a5][d-a7]) % mod;
					}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
