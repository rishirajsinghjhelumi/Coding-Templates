#include<stdio.h>
#include<algorithm>
#include<map>
#include<iostream>
#define mod 835454957
#define max 10000000
using namespace std;
typedef long long int ll;
ll counter;
int download[max+10];
int short_index,down,deleted,shortest;
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
				down--;
			if(short_index==down)
			{
				int k = 0;
				short_index = -1;
				shortest = mod+10;
				for(k=down-1;k>=0;k--)
					if(download[k]<shortest)
					{
						shortest=download[k];
						short_index = k;
					}
			}
		}
		else if(r%3==2)
		{
			download[down++] = r;
			if(r<shortest)
			{
				shortest = r;
				short_index = down-1;
			}
		}
	}
}
int main()
{
	int t,x;
	scanf("%d",&t);
	for(x=1;x<=t;x++)
	{
		int n,m,i;
		scanf("%d%d",&n,&m);
		int h[m];
		for(i=0;i<m;i++)
			scanf("%d",&h[i]);
		solve(n,m,h);
		printf("%d. %lld\n",x,counter);
	}
	return 0;
}
