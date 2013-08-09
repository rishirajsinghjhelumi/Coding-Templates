#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<VII> VVII;
typedef vector<VI> VVI;

#define INF 2000000000
#define INFLL (1LL<<62)
#define FI first
#define SE second
#define PB push_back
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({LL x;scanf("%lld", &x);x;})
#define MOD 1000000007

int aa[10],ss[10],R;
struct mat
{
	int A[8][8];
};
mat mul(const mat &a,const mat &b)
{
	int i,j,k;
	mat c;
	for(i=0;i<R;i++)
		for(j=0;j<R;j++)
			for(k=c.A[i][j]=0;k<R;k++)
				c.A[i][j]=(c.A[i][j]+(LL)a.A[i][k]*b.A[k][j])%MOD;
	return c;
}
mat add(const mat &a,const mat &b)
{
	int i,j;
	mat c;
	for(i=0;i<R;i++)
		for(j=0;j<R;j++)
			c.A[i][j]=(a.A[i][j]+b.A[i][j])%MOD;
	return c;
}

mat sub(const mat &a,const mat &b)
{
	mat c;
	int i,j;
	for(i=0;i<R;i++)
		for(j=0;j<R;j++)
			c.A[i][j]=(a.A[i][j]-b.A[i][j]+MOD)%MOD;
	return c;
}

mat one()
{
	mat c;
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<R;j++)
			c.A[i][j]=0;
		c.A[i][i]=1;
	}
	return c;
}

mat zero()
{
	mat c;
	int i,j;
	for(i=0;i<R;i++)
		for(j=0;j<R;j++)
			c.A[i][j]=0;
	return c;
}

mat powmod(mat a,int n)
{
	mat ans=one();
	while(n)
	{
		if(n%2)
			ans=mul(ans,a);
		n/=2;
		a=mul(a,a);
	}
	return ans;
}

mat sum(const mat &a,int n)	//calculates 1+a+a^2+....a^n-1
{
	if(n==1)
		return one();
	if(n%2==0)
	{
		mat S=sum(a,n/2),unit=one(),two=add(unit,unit);
		return mul(S,add(two,mul(S,sub(a,unit))));	//S*(2+(S*(a-1))); //S
	}
	return add(one(),mul(sum(a,n-1),a));	//S*a+1
}

mat initial()
{
	//S(n) = a1*S(n-1) + a2*S(n-2) + ... + aR*S(n-R)
	int i;
	mat a=zero();
	for(i=1;i<=R;i++)
		a.A[0][i-1]=aa[i];
	for(i=1;i<R;i++)
		a.A[i][i-1]=1;
	return a;
}

int nth(int n)
{
	if(n<=R)
		return ss[n];

	mat a=initial();
	mat ans=powmod(a,n-R);

	int ret=0,i;
	for(i=0;i<R;i++)
		ret=(ret+(LL)ss[R-i]*ans.A[0][i])%MOD;
	return ret;
}

int main()
{
	int i,j,n,t,kk,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&R,&k);
		for(i=1;i<=R;i++)
			scanf("%d",&ss[i]);
		for(i=1;i<=R;i++)
			scanf("%d",&aa[i]);
		int ans=0;
		mat a=initial();
		a=powmod(a,k);
		if(k<R)
		{
			for(kk=k; n && kk<R;kk+=k)
			{
				ans=(ans+nth(kk))%MOD;
				n--;
			}
		}
		else
			kk=k;
		if(n)
		{
			mat mans=sum(a,n);
			for(i=0;i<R;i++)
				ans=(ans+(LL)mans.A[0][i]*nth(kk-i))%MOD;
		}
		printf("%d\n",ans);
	}
	return 0;
}

