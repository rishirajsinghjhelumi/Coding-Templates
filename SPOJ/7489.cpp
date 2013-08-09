#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
#ifndef ONLINE_JUDGE
typedef __int64 LL;
#else
typedef long long LL;
#endif

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define N 111
int n;
LL k,m;
LL a[N][N];
int mark[N][N];
set< pair<LL,PII> > live;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d %lld %lld",&n,&k,&m);
		live.cl;
		int cnt=0;
		fill(mark,0);
		int i,j,h;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%lld",&a[i][j]);
				m-=a[i][j];
				if(a[i][j]>=k)
				{
					mark[i][j]=1;
					cnt++;
				}
			}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(a[i][j]<k)
				{
					for(h=0;h<4;h++)
					{
						int x=i+dx[h];
						int y=j+dy[h];
						if(0<=x && x<n && 0<=y && y<n && a[x][y]>=k) break;
					}
					if(h<4)
					{
						mark[i][j]=1;
						cnt++;
						live.insert(mp(-a[i][j],mp(i,j)));
					}
				};
		if(m<=0){puts("0");continue;}
		if(cnt==0){puts("Not possible");continue;}
		LL ans=0;
		LL dif=0;
		for(;;)
		{
			if(live.empty())
			{
				ans+=(m+cnt-1)/cnt;
				break;
			}
			pair<LL,PII> p=*live.begin();
			LL val=-p.first+dif;
			int i=p.second.first;
			int j=p.second.second;
			LL d=k-val;
			if(m<=d*cnt)
			{
				ans+=(m+cnt-1)/cnt;
				break;
			}
			ans+=d;
			m-=cnt*d;
			dif+=d;
			live.erase(live.begin());
			for(h=0;h<4;h++)
			{
				int x=i+dx[h];
				int y=j+dy[h];
				if(0<=x && x<n && 0<=y && y<n && !mark[x][y])
				{
					mark[x][y]=1;
					cnt++;
					live.insert(mp(-a[x][y]+dif,mp(x,y)));
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
