#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<ctype.h>
#include<string>
#include<cstring>
#include<iostream>

#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<bitset>
#include<set>
#include<list>
#include<complex>

#define GC getchar_unlocked
#define MAX(a,b) ({a>b?a:b;})
#define MIN(a,b) ({a>b?b:a;})
#define P(x) printf("%d\n",x);
#define PLL(x) printf("%lld\n",x);
#define MP make_pair
#define PB push_back
#define SZ size()
#define CL clear()
#define X first
#define Y second
#define MOD 1000000007
#define max 110

using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<pair<int,int> > VPII;
typedef stack<int> SI;

template<class T>inline T input(T x){char c=GC();x=0;T s=1;while(c<48||c>57){if(c=='-')s=-1;c=GC();}while(c>=48&&c<=57){x=(x<<3)+(x<<1)+c-48;c=GC();}return x*s;}
template<class T>inline void output(T a){if(a){T v=a%10;output(a/10);putchar((char)(v+'0'));}}
template<class T>inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T>inline T modinv(T a,T n){T i=n,v=0,d=1;while(a>0){T t=i/a,x=a;a=i%x;i=x;x=d;d=v-t*x;v=x;}return (v+n)%n;}
LL modpow(LL n ,LL k,LL mod){LL ans=1;while(k>0){if(k&1)ans=(ans*n)%mod;k>>=1;n=(n*n)%mod;}return ans%mod;}

int a[max];
int p[max];
int pa[max][max];
int pk[max][max];

void knapsack(int n,int W,int *weight,int *value,int res[][max])
{
	int i,j,w;
	for(w=0;w<=W;w++)
		res[0][w] = 0;
	for(i=0;i<n;i++)
		res[i][0] = 0;
	for(i=1;i<=n;i++)
	{
		for(w=1;w<=W;w++)
		{
			if(weight[i-1] <= w)
				res[i][w] = MAX(res[i-1][w],value[i-1] + res[i-1][w-weight[i-1]]);
			else
				res[i][w] = res[i-1][w];
		}
	}
}

int main()
{
	int t = input(t);
	while(t--)
	{
		int n = input(n);
		int i,j,weight=0;
		for(i=0;i<n;i++)
		{
			a[i] = input(a[i]);
			weight += a[i];
		}
		for(i=0;i<n;i++)
			p[i] = input(p[i]);
		knapsack(n,weight,a,p,pa);
	}
	return 0;
}
