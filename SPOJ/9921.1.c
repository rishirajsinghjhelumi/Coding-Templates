#include<stdio.h>
char a[100][100],str[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int done=0,l=0,max = 0;
int table[100][100];
int checkit(int ,int ,int , int, int);
int main()
{
	int i,j,r,c,k,l,t=1;
	char ch;
	scanf("%d%d%*c",&r,&c);
	while(r!=0 && c!=0)
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%c",&a[i][j]);
				table[i][j] = 0;
			}
			scanf("%*c");
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				checkit(r,c,i,j,0);
			}
		}
		printf("Case %d: %d\n",t++,max);
		scanf("%d%d%*c",&r,&c);
		max = 0;
	}
	return 0;
}
int checkit(int r,int c,int i,int j,int l)
{
	if(l > max)
		max = l;
	if(max >= 26)
		return;
	if(a[i][j]==str[l])
	{
		l++;
		if(i-1>=0)
		{
			checkit(r,c,i-1,j,l);
			if(j-1>=0)
				checkit(r,c,i-1,j-1,l);
			if(j+1<c)
				checkit(r,c,i-1,j+1,l);
		}
		if(i+1<r)
		{
			checkit(r,c,i+1,j,l);
			if(j-1>=0)
				checkit(r,c,i+1,j-1,l);
			if(j+1<c)
				checkit(r,c,i+1,j+1,l);
		}
		if(j-1>=0)
			checkit(r,c,i,j-1,l);
		if(j+1<c)
			checkit(r,c,i,j+1,l);
	}
	return;
}
