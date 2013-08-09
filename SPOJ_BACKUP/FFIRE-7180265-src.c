#include<stdio.h>
int a[10][10],min;
char c[10][10],s[10][10];
int checkit(int i,int j);
void copy();
void init();
int main()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			scanf("%c",&c[i][j]);
			s[i][j] = c[i][j];
		}
		scanf("%*c");
	}
	int count = 0,check = 1;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			if(c[i][j]=='T')
			{
				init();
				if(!checkit(i,j))
				{
					check = 0;
					break;
				}
			}
		if(!check)
			break;
	}
	int done=0;
	if(check)
	{
		while(1)
		{
			done = 1;
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
					if(c[i][j] == 'T')
					{
						done=0;
						break;
					}
				if(!done)
					break;
			}
			if(done)
				break;
			count++;
			for(i=0;i<10;i++)
				for(j=0;j<10;j++)
					if(c[i][j] == 'F')
					{
						if(i-1>=0 && c[i-1][j]=='T')
							s[i-1][j] = 'F';
						if(i+1<10 && c[i+1][j]=='T')
							s[i+1][j] = 'F';
						if(j-1>=0 && c[i][j-1]=='T')
							s[i][j-1] = 'F';
						if(j+1<10 && c[i][j+1]=='T')
							s[i][j+1] = 'F';
					}
			copy();
		}
	}
	printf("%d",check?count:-1);
	return 0;
}
void copy()
{
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			c[i][j] = s[i][j];
}
void init()
{
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			a[i][j] =0;
}
int checkit(int i,int j)
{
	if(i==10 || j==10 || i==-1 || j==-1 || a[i][j])
		return 0;
	a[i][j] = 1;
	if(c[i][j]=='F')
		return 1;
	else if(c[i][j] == '.')
		return 0;
	else
		return checkit(i-1,j)+checkit(i+1,j)+checkit(i,j-1)+checkit(i,j+1);
}
