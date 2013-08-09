#include<stdio.h>
int path(int,int,int,int [],int);
int res = 999999;
int main()
{
	int n,m,i,c;
	while(scanf("%d %d",&n,&m) != EOF)
	{
		int a[m];
		for(i=0;i<m;i++)
			scanf("%d",&a[i]);
		c = path(1,n,m,a,0);
	}
	return 0;
}
int path(int pos,int n,int m,int a[],int count)
{
	int i;
	static int counter = 0;
	for(i=0;i<m;i++)
	{
		pos = pos * a[i];
		if(pos >=n )
		{
			if(count < res && pos == n)
				res = count;
		}
		else if(pos < n)
		{
			count++;
			path(pos,n,m,a,count);
		}
	}
	if(res==999999)
		res = -1;
	printf("%d  ",count);
	res = 999999;
	count = 0;
}
