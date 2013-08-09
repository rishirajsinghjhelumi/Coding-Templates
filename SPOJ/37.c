#include<stdio.h>
int main()
{
	int i,test_cases;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		int r1,c1,r2,c2,j,k,l,dep=0;
		scanf("%d%d",&r1,&c1);
		char ke[r1][c1],ch;
		int key[r1][c1];
		scanf("%c",&ch);
		for(j=0;j<r1;j++)
		{
			for(k=0;k<c1;k++)
			{
				scanf("%c",&ke[j][k]);
				if(ke[j][k] == '#')
					key[j][k] = 1;
				else
					key[j][k] = 0;
			}
			scanf("%c",&ch);
		}
		scanf("%d%d",&r2,&c2);
		scanf("%c",&ch);
		char loc[r2][c2];
		int lock[r2][c2];
		for(j=0;j<r2;j++)
		{
			for(k=0;k<c2;k++)
			{
				scanf("%c",&loc[j][k]);
				if(loc[j][k] == '#')
					lock[j][k] = 1;
				else
					lock[j][k] = 0;
			}
			scanf("%c",&ch);
		}
		for(j=0;j<r1;j++)
		{
			for(k=0;k<c1;k++)
				printf("%d",key[j][k]);
			printf("\n");
		}
		for(j=0;j<c2;j++)
		{
			for(k=0;k<r1;k++)
			{
				for(l=0;l<c1;l++)
				{
					if(key[k][l] =! lock[k][l])
				}
			}
		}
	}
	return 0;
}
