#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d%*c",&test_cases);
	while(test_cases--)
	{
		char a[3][3],winx=0,wino=0;
		int countx=0,counto=0,i,j;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%c",&a[i][j]);
				if(a[i][j]=='X')
					countx++;
				else if(a[i][j]=='O')
					counto++;
			}
			scanf("%*c");
		}
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
		if(wino!=0 && winx!=0)
			printf("no\n");
		else if(wino==0 && winx ==0)
		{
			if(countx - counto == 0 || countx - counto == 1)
				printf("yes\n");
			else
				printf("no\n");
		}
		else if(winx !=0 && wino==0)
		{
			if(countx - counto == 1)
				printf("yes\n");
			else
				printf("no\n");
		}
		else if(winx==0 && wino!=0)
		{
			if(countx == counto)
				printf("yes\n");
			else
				printf("no\n");
		}
		scanf("%*c");
	}
	return 0;
}
