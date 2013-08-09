#include<stdio.h>
char a[100][100],str[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int done=0,l=0,max = 0;
int checkit(int ,int ,int , int, int);
int main()
{
	int i,j,r,c,k,l,t=1;
	char ch;
	scanf("%d%d",&r,&c);
	while(r!=0 && c!=0)
	{
		for(i=0;i<r;i++)
		{
			scanf("%c",&ch);
			for(j=0;j<c;j++)
				scanf("%c",&a[i][j]);
		}
		int table[r][c];
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				table[i][j] = 0;
		l = 1;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(a[i][j] == str[table[i][j]])
				{
					if(i+1<r)
					{
						table[i+1][j] = table[i][j]+1;
						if(j-1>=0)
							table[i+1][j-1] = table[i][j]+1;
						if(j+1<c)
							table[i+1][j+1] = table[i][j]+1;
					}
					if(i-1>=0)
					{
						table[i-1][j] = table[i][j]+1;
						if(j-1>=0)
							table[i-1][j-1] = table[i][j]+1;
						if(j+1<c)
							table[i-1][j+1] = table[i][j]+1;
					}
					if(j-1>=0)
						table[i][j-1] = table[i][j]+1;
					if(j+1<c)
						table[i][j+1] = table[i][j]+1;
				}
			}
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				printf("%d ",table[i][j]);
			printf("\n");
		}
		printf("Case %d: %d\n",t++,max);
		scanf("%d%d",&r,&c);
		max = 0;
	}
	return 0;
}
