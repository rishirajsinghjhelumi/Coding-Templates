#include<stdio.h>
#include<string.h>
int main()
{
	while(1)
	{
		char a[3][3],winx=0,wino=0;
		int countx=0,counto=0,i,j;
		scanf("%c%c%c",&a[0][0],&a[0][1],&a[0][2]);
		if(a[0][0] == 'e' && a[0][1] == 'n' && a[0][2] == 'd')
		{
			scanf("%*c");
			break;
		}
		if(a[0][0] == 'X')
			countx++;
		else if(a[0][0]=='O')
			counto++;
		if(a[0][1] == 'X')
			countx++;
		else if(a[0][1]=='O')
			counto++;
		if(a[0][2] == 'X')
			countx++;
		else if(a[0][2]=='O')
			counto++;
		for(i=1;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%c",&a[i][j]);
				if(a[i][j]=='X')
					countx++;
				else if(a[i][j]=='O')
					counto++;
			}
		}
		scanf("%*c");
		for(i=0;i<3;i++)
			if(a[i][0] == 'X' && a[i][1] == 'X' && a[i][2] == 'X')
				winx++;
		for(i=0;i<3;i++)
			if(a[i][0] == 'O' && a[i][1] == 'O' && a[i][2] == 'O')
				wino++;
		for(i=0;i<3;i++)
			if(a[0][i] == 'X' && a[1][i] == 'X' && a[2][i] == 'X')
				winx++;
		for(i=0;i<3;i++)
			if(a[0][i] == 'O' && a[1][i] == 'O' && a[2][i] == 'O')
				wino++;
		if(a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X')
			winx++;
		if(a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O')
			wino++;
		if(a[0][2] == 'X' && a[1][1] == 'X' && a[2][0] == 'X')
			winx++;
		if(a[0][2] == 'O' && a[1][1] == 'O' && a[2][0] == 'O')
			wino++;
		if(wino==0 && winx==0 && countx+counto!=9)
			printf("invalid\n");
		else if(wino!=0 && winx!=0)
			printf("invalid\n");
		else if(wino==0 && winx ==0 && countx+counto==9)
		{
			if(countx - counto == 0 || countx - counto == 1)
				printf("valid\n");
			else
				printf("invalid\n");
		}
		else if(winx !=0 && wino==0)
		{
			if(countx - counto == 1)
				printf("valid\n");
			else
				printf("invalid\n");
		}
		else if(winx==0 && wino!=0)
		{
			if(countx == counto)
				printf("valid\n");
			else
				printf("invalid\n");
		}
	}
	return 0;
}
