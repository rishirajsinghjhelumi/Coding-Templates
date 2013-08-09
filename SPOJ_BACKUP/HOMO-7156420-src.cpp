#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
char ans[4][100]={"both","homo","hetero","neither"};
int main()
{
	int n,l=0,len1=0,count=0;
	scanf("%d",&n);
	map<const int,int>e;
	while(n--)
	{
		char str[100];
		int num;
		scanf("%s%d",str,&num);
		if(strcmp(str,"insert")==0)
		{
			l++;
			if(e.find(num)!=e.end())
			{
				e[num]++;
				count--;
			}
			else
			{
				e[num]=1;
				count++;
				len1++;
			}
			int homo=0,hetero=0;
			if(len1>=2)
				hetero=1;
			if(count!=l)
				homo=1;
			if(homo && hetero)
				printf("%s\n",ans[0]);
			else if(homo && !hetero)
				printf("%s\n",ans[1]);
			else if(!homo && hetero)
				printf("%s\n",ans[2]);
			else
				printf("%s\n",ans[3]);
		}
		else
		{
			if(e.find(num)!=e.end())
			{
				l--;
				e[num]--;
				if(!e[num])
				{
					e.erase(num);
					count--;
					len1--;
				}
				else if(e[num]==1)
					count++;
			}
			int homo=0,hetero=0;
			if(len1>=2)
				hetero=1;
			if(count!=l)
				homo=1;
			if(homo && hetero)
				printf("%s\n",ans[0]);
			else if(homo && !hetero)
				printf("%s\n",ans[1]);
			else if(!homo && hetero)
				printf("%s\n",ans[2]);
			else
				printf("%s\n",ans[3]);
		}
	}
	return 0;
}
