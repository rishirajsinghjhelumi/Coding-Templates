#include<stdio.h>
char a[1000][1000],b[5000][5000];
int count[2000][2];
int main()
{
	int n1,n2,m1,m2,i,j,k,l,m,add=0,check;
	scanf("%d%d%*c",&n1,&n2);
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
			scanf("%c",&a[i][j]);
		scanf("%*c");
	}
	scanf("%d%d%*c",&m1,&m2);
	for(i=0;i<m1;i++)
	{
		for(j=0;j<m2;j++)
			scanf("%c",&b[i][j]);
		scanf("%*c");
	}
	for(i=0;i<=m1-n1;i++)
	{
		for(j=0;j<=m2-n2;j++)
		{
			check = 1;
			for(l=0;l<n1;l++)
			{
				for(k=0;k<n2;k++)
				{
					if(a[l][k]!=b[l+i][k+j])
					{
						check = 0;
						break;
					}
				}
				if(!check)
					break;
			}
			if(check)
			{
				count[add][0] = i+1;
				count[add++][1] = j+1;
			}
		}
	}
	if(add==0)
		printf("NO MATCH FOUND...\n");
	else
		for(i=0;i<add;i++)
			printf("(%d,%d)\n",count[i][0],count[i][1]);
	return 0;
}
