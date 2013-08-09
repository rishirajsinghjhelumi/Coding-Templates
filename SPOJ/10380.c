#include<stdio.h>
#define max 100000
int q[10*max],a[max][100];
int input()
{
	register int c = getchar_unlocked();
	int x=0;
	while(c<48 || c>57)
		c=getchar_unlocked();
	while(c>=48 && c<=57)
	{
		x = (x<<3)+(x<<1)+c-48;
		c = getchar_unlocked();
	}
	return x;
}
int main()
{
	int t=input();
	while(t--)
	{
		int n=input(),e=input(),x,y;
		int color[max]={0},ind[max]={0},j,count=0;
		while(e--)
		{
			x = input();
			y = input();
			a[x][ind[x]++] = y;
			a[y][ind[y]++] = x;
		}
		for(j=0;j<n;j++)
		{
			if(color[j])
				continue;
			int l=0,x=0,i,u,s,c;
			q[l++] = j;
			color[j] = 1;
			while(x!=l)
			{
				u = q[x++];
				s = ind[u];
				for(i=0;i<s;i++)
				{
					c = a[u][i];
					if(!color[c])
						color[c] = 1,q[l++] = c;
				}
			}
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
