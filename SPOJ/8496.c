#include<stdio.h>
#include<math.h>
#define max 100000
#define root (int)sqrt(max)
int a[max+10];
int count[max+10][10];
int main()
{
	int i,j,s,x,k;
	for(i=2;i<=root;i++)
	{
		s = i*i;
		for(j=s;j<=max;j+=s)
			a[j] = 1;
	}
	for(i=1;i<=max;i++)
	{
		if(!a[i])
		{
			x = i;
			while(x)
			{
				k = x%10;
				count[i][k] = count[i-1][k]+1;
				x/=10;
			}
			for(j=0;j<10;j++)
				if(count[i][j]==0)
					count[i][j] = count[i-1][j];
		}
		else
		{
			for(j=0;j<10;j++)
				count[i][j] = count[i-1][j];
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int A,b,d,c=0;
		scanf("%d%d%d",&A,&b,&d);
		printf("%d\n",count[b][d] - count[A-1][d]);
	}
	return 0;
}
