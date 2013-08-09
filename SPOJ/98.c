#include<stdio.h>
#include<math.h>
#include<assert.h>
int count = 0;
char a[500][500],b[500][500];
int steps[5000][2],m_steps[5000][2];
int min = 1000000;
int toggle_binary(int * , int , int,int );
int button_toggle_row(int * , int  , int,int);
int check_solution(int,int);
int main()
{
	int i,test_cases;
	int r,c,j,k,l,x;
	scanf("%d%d%*c",&c,&r);
	while(r!=0 && c!=0)
	{
		assert(r>=3 && r<=15 && c>=3 && c<=15);
		int binary[c];
		char ch;
		for(j=0;j<r;j++)
		{
			for(k=0;k<c;k++)
			{
				scanf("%c",&ch);
				b[j][k] = a[j][k] = (ch=='0')?'.':'X';
			}
			scanf("%*c");
		}
		toggle_binary(binary,c,r,x);
		if(min==1000000)
			min=-1;
		printf("%d\n",min);
		for(j=0;j<min;j++)
			printf("%d %d\n",m_steps[j][0]+1,m_steps[j][1]+1);
		count = 0;
		min = 1000000;
		scanf("%d%d%*c",&c,&r);
	}
	return 0;
}
int toggle_binary(int *binary , int c ,int r,int x)
{
	int i,j,e,d,k,m;
	int power=1<<c;
	for(i=0;i<power;i++)
	{
		d = i;
		for(j=c-1;j>=0;j--)
		{
			e = d % 2;
			d >>=1;
			binary[j] = (e == 0) ?0:1;
		}
		button_toggle_row(binary,c,r,x);
		count = 0;
		for(j=0;j<r;j++)
			for(k=0;k<c;k++)
				a[j][k] = b[j][k];
	}
}
int button_toggle_row(int *binary , int c  ,int r,int x)
{
	int j,k,l,row;
	for(j=0;j<c;j++)
		if( binary[j] == 1 )
		{
			steps[count][0] = j;
			steps[count][1] = 0;
			a[0][j] = (a[0][j]=='X')?'.':'X';
			if( j  > 0  )
				a[0][j-1] = (a[0][j-1]=='X')?'.':'X';
			if( j + 1 < c )
				a[0][j+1] = (a[0][j+1]=='X')?'.':'X';
			if(r > 1)
				a[1][j] = (a[1][j]=='X')?'.':'X';
			count++;
		}
	for(row=0;row<r-1;row++)
		for(j=0;j<c;j++)
			if( a[row][j] == '.' )
			{
				steps[count][0] = j;
				steps[count][1] = row+1;
				a[row+1][j] = (a[row+1][j]=='X')?'.':'X';
				a[row][j] = (a[row][j]=='X')?'.':'X';
				if( row + 2 < r )
					a[row+2][j] = (a[row+2][j]=='X')?'.':'X';
				if( j - 1 >=0)
					a[row+1][j-1] = (a[row+1][j-1]=='X')?'.':'X';
				if( j + 1 < c )
					a[row+1][j+1] = (a[row+1][j+1]=='X')?'.':'X';
				count++;
			}
	if(check_solution(r,c))
	{
		for(j=0;j<count;j++)
			m_steps[j][0]=steps[j][0],m_steps[j][1]=steps[j][1];
		if( count < min )
			min = count;
	}
}
int check_solution(int r,int c)
{
	int j,done=1;
	for(j=0;j<c;j++)
		if(a[r-1][j] == '.' )
		{
			done = 0;
			break;
		}
	return done;
}
