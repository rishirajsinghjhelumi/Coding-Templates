#include<stdio.h>
#define m1 19
#define m2 55
#define m3 37
typedef long long int lld;
lld dp[20][55][37][20][20],pow9[20];
lld mod =  1<<16;
lld res[37][60][38][26][22];
lld pow2[20]= {0 , 0 , 9 , 171 , 2439 , 30951 , 368559 , 4217031 , 46953279LL , 512579511LL , 1218248303LL , 2784365543LL , 3390140191LL , 2798325783LL , 1458643151LL , 3498166087LL , 3906748799LL , 4206415223LL , 3192404271LL , 4200858279LL };
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
lld mulmod( lld a,lld b,lld c)
{
	lld x = 0,y=a%c;
	while(b > 0)
	{
		if(b&1)
			x = (x+y)%c;
		y = (y<<1)%c;
		b >>=1;
	}
	return x%c;
}
void calc1()
{
	int a,b,c,d,len,i,j,k=0;
	dp[0][0][0][0][0] = 1;
	for(len=1;len<m1;len++)
		for(a=0;a<m2;a++)
		{
			for(b=0;b<m3;b++)
			{
				for(c=0;c<m1;c++)
				{
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
							if(!count)
								break;
						}
					if(!dp[len][a][b][c][0])
						break;
				}
				if(!dp[len][a][b][0][0])
					break;
			}
			if(!dp[len][a][0][0][0])
				break;
		}
}
void calc2(int a2,int a3,int a5,int a7,int l)
{
	int num = (l+1)/2;
	int den = l/2,a,b,c,d;
	lld ans = 0,s1,s2,s3,s4;
	for(a=a2;dp[num][a][0][0][0] && dp[den][a-a2][0][0][0] && a<m2 && a-a2<m2;a++)
	{
		s1 = 0;
		for(b=a3;dp[num][a][b][0][0] && dp[den][a-a2][b-a3][0][0] && b<m3 && b-a3<m3;b++)
		{
			s2 = 0;
			for(c=a5;dp[num][a][b][c][0] && dp[den][a-a2][b-a3][c-a5][0] && c<m1 && c-a5<m1;c++)
			{
				s3 = 0;
				for(d=a7;dp[num][a][b][c][d] && dp[den][a-a2][b-a3][c-a5][d-a7] && d<m1 && d-a7<m1;d++)
				{
					s4 = ( dp[num][a][b][c][d] * dp[den][a-a2][b-a3][c-a5][d-a7]) % mod;
					res[l][a][b][c][d] = s4;
					s3 += s4;
				}
				res[l][a][b][c][a7] = s3;
				s2 += s3;
			}
			res[l][a][b][a5][a7] = s2;
			s1 += s2;
		}
		res[l][a][a3][a5][a7] = s1;
		ans += s1;
	}
	res[l][a2][a3][a5][a7] = ans;
}
void calc3()
{
	int l;
	for(l=1;l<m3;l++)
	{
		calc2(0,0,0,0,l);
		//calc2(0,1,0,0,l);
		//calc2(0,0,1,0,l);
		//calc2(0,0,0,1,l);
	}
}
int main()
{
	mod *= mod;
	calc1();
	calc3();
	int a,b,c,d,len,i,j,k=0;
	lld t,v,l;
	pow9[0] = 1;
	for(t=1;t<20;t++)
		pow9[t] = (pow9[t-1] * 9) % mod;
	t = input();
	while(t--)
	{
		l = input();
		v = input();
		int num = (l+1)/2,den = l/2,f[4] = {2,3,5,7},factor[4]={0,0,0,0};
		if(!v)
		{
			printf("%lld\n",l==1?1:mulmod(pow9[den],pow2[num],mod));
			continue;
		}
		for(i=0;i<4;i++)
		{
			int x = f[i];
			while(v % x == 0)
			{
				v /= x;
				factor[i]++;
			}
		}
		if(v!=1)
		{
			printf("0\n");
			continue;
		}
		int a2=factor[0],a3=factor[1],a5=factor[2],a7=factor[3];
		lld ans = res[l][a2][a3][a5][a7];
		printf("%lld\n",ans);
	}
	return 0;
}
