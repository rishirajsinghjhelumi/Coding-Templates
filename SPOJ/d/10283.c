#include<stdio.h>
char a[100][100],str[]="ALLIZZWELL";
int check[100][100],done=0,l=0;
int checkit(int ,int ,int , int, int);
void initialize(int r,int c);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int i,j,r,c,k,l;
		char ch;
		scanf("%d%d",&r,&c);
		scanf("%*c");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%c",&a[i][j]);
				check[i][j] = 0;
			}
			scanf("%*c");
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				checkit(r,c,i,j,0);
				if(done==1)
					break;
			}
			if(done==1)
				break;
		}
		printf("%s\n",done==1?"YES":"NO");
		done=0;
	}
	return 0;
}
void initialize(int r, int c)
{
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			check[i][j] = 0;
}
int checkit(int r,int c,int i,int j,int l)
{
	//printf("str[%d]->%c==a[%d][%d]->%c\n",l,str[l],i,j,a[i][j]);
	if(l==10)
	{
		done=1;
		return;
	}
	if(done==1)
		return;
	if(check[i][j] == 1)
		return;
	if(a[i][j]==str[l])
	{
		l++;
		check[i][j] = 1;
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
		check[i][j] = 0;
	}
	return;
}
