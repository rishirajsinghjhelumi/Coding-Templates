#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[3],b[2];
	while(scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&b[0],&b[1]) && (a[0]|a[1]|a[2]|b[0]|b[1]))
	{
		int card[53]={0},i,min=-1;
		card[a[1]]=card[a[0]]=card[a[2]]=card[b[1]]=card[b[0]]=1;
		sort(a,a+3);
		sort(b,b+2);
		if(a[2] < b[0])
		{
			for(i=1;i<=52;i++)
				if(!card[i])
				{
					min = i;
					break;
				}
		}
		else if(a[2] > b[1])
		{
			if(a[1] > b[0])
				min = -1;
			else
			{
				for(i=a[1]+1;i<=52;i++)
					if(!card[i])
					{
						min = i;
						break;
					}
			}
		}
		else if(a[2] < b[1] && a[2] > b[0])
		{
			if(a[1] < b[0])
			{
				for(i=a[1]+1;i<=52;i++)
					if(!card[i])
					{
						min = i;
						break;
					}
			}
			else if(a[1] > b[0])
			{
				for(i=a[2]+1;i<=52;i++)
					if(!card[i])
					{
						min = i;
						break;
					}
			}
			else if(a[0] > b[0])
			{
				for(i=a[2]+1;i<=52;i++)
					if(!card[i])
					{
						min = i;
						break;
					}
			}	
		}
		printf("%d\n",min);
	}
	return 0;
}
