#include<stdio.h>
#include<math.h>
static int count = 0;
char a[50][50],b[50][50];
int min = 1000000;
int toggle_binary(int * , int , int);
int button_toggle_row(int * , int  , int);
int check_solution(int,int);
int main()
{
	int i,test_cases;
	int r,c,j,k,l;
	scanf("%d%d",&r,&c);
	while(r!=0 && c!=0)
	{
		int binary[c];
		char ch;
		for(j=0;j<r;j++)
		{
			scanf("%c",&ch);
			for(k=0;k<c;k++)
			{
				scanf("%c",&a[j][k]);
				b[j][k] = a[j][k];
			}
		}
		toggle_binary(binary,c,r);
		if(min == 1000000)
			printf("Damaged billboard.\n");
		else
			printf("You have to tap %d tiles.\n",min);
		count = 0;
		min = 1000000;
		scanf("%d%d",&r,&c);
	}
	return 0;
}
int toggle_binary(int *binary , int c ,int r)
{
	int i,j,e,d,k;
	for(i=0;i<pow(2,c);i++)
	{
		d = i;
		for(j=c-1;j>=0;j--)
		{
			e = d % 2;
			d = d / 2;
			if( e == 0 )
				binary[j] = 0;
			else
				binary[j] = 1;
		}
		button_toggle_row(binary,c,r);
		count = 0;
		for(j=0;j<r;j++)
			for(k=0;k<c;k++)
				a[j][k] = b[j][k];
	}
}
int button_toggle_row(int *binary , int c  ,int r)
{
	int j,k,l,row;
	for(j=0;j<c;j++)
		if( binary[j] == 1 )
		{
			if( a[0][j] == 'X' )
				a[0][j] = '.';
			else if( a[0][j] == '.' )
				a[0][j] = 'X';
			if( j  > 0  )
			{
				if( a[0][j-1] == 'X' )
					a[0][j-1] = '.';
				else if( a[0][j-1] == '.' )
					a[0][j-1] = 'X';
			}
			if( j + 1 < c )
			{
				if( a[0][j+1] == 'X' )
					a[0][j+1] = '.';
				else if( a[0][j+1] == '.' )
					a[0][j+1] = 'X';
			}
			if(r > 1)
			{
				if( a[1][j] == 'X' )
					a[1][j] = '.';
				else if( a[1][j] == '.' )
					a[1][j] = 'X';
			}
			count++;
		}
	for(row=0;row<r-1;row++)
	{
		for(j=0;j<c;j++)
		{
			if( a[row][j] == 'X' )
			{
				if( a[row+1][j] == 'X' )
					a[row+1][j] = '.';
				else if( a[row+1][j] == '.' )
					a[row+1][j] = 'X';
				if( a[row][j] == 'X' )
					a[row][j] = '.';
				else if( a[row][j] == '.' )
					a[row][j] = 'X';
				if( row + 2 < r )
				{
					if( a[row+2][j] == 'X' )
						a[row+2][j] = '.';
					else if( a[row+2][j] == '.' )
						a[row+2][j] = 'X';
				}
				if( j - 1 >=0)
				{
					if( a[row+1][j-1] == 'X' )
						a[row+1][j-1] = '.';
					else if( a[row+1][j-1] == '.' )
						a[row+1][j-1] = 'X';
				}
				if( j + 1 < c )
				{
					if( a[row+1][j+1] == 'X' )
						a[row+1][j+1] = '.';
					else if( a[row+1][j+1] == '.' )
						a[row+1][j+1] = 'X';
				}
				count++;
			}
		}
	}
	if(check_solution(r,c)==1)
		if( count < min )
			min = count;
}
int check_solution(int r,int c)
{
	int j,done=0;
	for(j=0;j<c;j++)
	{
		if(a[r-1][j] == '.' )
			done = 1;
		else
		{
			done = 0;
			break;
		}
	}
	return done;
}
