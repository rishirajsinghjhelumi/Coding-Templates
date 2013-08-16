#include<stdio.h>
#include<cmath>
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

#define GC getchar_unlocked
#define mod 1000000007
#define MAX(a,b) ({a>b?a:b;})
#define MIN(a,b) ({a>b?b:a;})
#define MP make_pair
#define PB push_back
#define max 100000

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

vector <int> a[max+10];
queue<int> Q;

int color[max+10];
int val[max+10];

template<class T>inline T input(T x){char c=GC();x=0;T s=1;while(c<48||c>57){if(c=='-')s=-1;c=GC();}while(c>=48&&c<=57){x=(x<<3)+(x<<1)+c-48;c=GC();}return x*s;}

int main()
{
	int n,m,i,j,l,r,x;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		l = input(l) - 1;
		r = input(r) - 1;
		a[l].PB(r);
		a[r].PB(l);
	}
	for(i=0;i<n;i++)
		color[i] = 0;
	for(j=0;j<n;j++)
	{
		if(color[j])
			continue;
		color[j] = 1;
		Q.push(j);
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for(i=0;i<a[u].size();i++)
			{
				int s = a[u][i];
				if(!color[s])
				{
					color[s] = 1;
					Q.push(s);
				}
			}
		}
	}
	return 0;
}
