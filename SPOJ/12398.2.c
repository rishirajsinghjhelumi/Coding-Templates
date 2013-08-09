#include<stdio.h>
#include<algorithm>
#include<map>
#include<iostream>
#define mod 835454957
#define max 10000000
using namespace std;
typedef long long int ll;
ll counter = 0;
int short_index,down,deleted,shortest;
map<int,int>download;
map<int,int>::iterator it;
bool compare(pair<int,int> i, pair<int, int> j) 
{
	  return i.second < j.second;
}
void solve(int n,int m,int *h)
{
	short_index = -1;
	down = 0;
	shortest = mod+10;
	counter = 0;
	int i,j=0,s,r;
	for(i=0;i<n;i++)
	{
		r = h[j];
		s = (j+1)%m;
		h[j] = ( ( h[j] ^ h[s] ) + 13 ) % mod;
		j = s;
		if(r%3==0)
		{
			if(short_index!=-1)
				counter += shortest;
		}
		else if(r%3==1)
		{
			if(down)
				download.erase(--down);
			if(!down)
			{
				short_index = -1;
				shortest = mod+10;
			}
			else
			{
				//pair<int, int> min = *min_element(download.begin(), download.end(), compare);
				it = download.begin();
				short_index = (*it).first;
				shortest = (*it).second;
			}
		}
		else
		{
			download[down++] = r;
			if(r<shortest)
			{
				shortest = r;
				short_index = down-1;
			}
		}
	}
	download.clear();
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i;
		scanf("%d%d",&n,&m);
		int h[m];
		for(i=0;i<m;i++)
			scanf("%d",&h[i]);
		solve(n,m,h);
		printf("%lld\n",counter);
	}
	return 0;
}
