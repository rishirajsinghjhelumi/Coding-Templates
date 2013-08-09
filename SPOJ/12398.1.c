#include<stdio.h>
#include<algorithm>
#include<map>
#include<iostream>
#define mod 835454957
#define max 10000000
using namespace std;
typedef long long int ll;
ll counter = 0;
int r[max+10];
int short_index,down,deleted,shortest;
map<int,int>download;
map<int,int>::iterator it;
bool compare(pair<int,int> i, pair<int, int> j) 
{
	  return i.second < j.second;
}
void gen_r(int n,int m,int *h)
{
	int i,j=0,s;
	for(i=0;i<n;i++)
	{
		r[i] = h[j];
		s = (j+1)%m;
		h[j] = ( ( h[j] ^ h[s] ) + 13 ) % mod;
		j = s;
		printf("%d ",r[i]);
	}
	printf("\n");
	short_index = -1;
	down = 0;
	deleted = 0;
	shortest = mod+10;
	counter = 0;
}
void solve(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(r[i]%3==0)
		{
			if(short_index!=-1)
			{
				counter += shortest;
				printf("shortest added %d count == %lld\n",shortest,counter);
			}
			else
				printf("no shortest\n");
		}
		else if(r[i]%3==1)
		{
			if(download.size())
			{
				it = download.find(deleted);
				if(it!=download.end())
					download.erase(it);
				deleted++;
			}
			if(download.size()==0)
			{
				short_index = -1;
				shortest = mod+10;
				printf("0 size shortest = none\n");
			}
			else
			{
				pair<int, int> min = *min_element(download.begin(), download.end(), compare);
				short_index = min.first;
				shortest = min.second;
				printf("MINIMUM is %d\n",shortest);
			}
		}
		else
		{
			download[down++] = r[i];
			if(r[i]<shortest)
			{
				shortest = r[i];
				short_index = down-1;
				printf("shortest == %d\n",shortest);
			}
			printf("-----\n");
			for ( it=download.begin() ; it != download.end(); it++ )
				    cout << (*it).first << " => " << (*it).second << endl;
			printf("------\n");
		}
	}
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
		gen_r(n,m,h);
		solve(n);
		printf("%lld\n",counter);
		download.clear();
	}
	return 0;
}
