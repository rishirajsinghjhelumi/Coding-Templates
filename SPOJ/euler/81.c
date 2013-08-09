#include<stdio.h>
int x=0,n,t,min=99999999;
int mat[100][100];
c(int a,int b,int sum)
{
	if(a==n-1&&b==n-1)
	{
		if(sum < min)
			min = sum;
		return;
	}
	if(a+1<n)
		c(a+1,b,sum+mat[a][b]);
	if(b+1<n)
		c(a,b+1,sum+mat[a][b]);
	return;
}
main()
{
	int i,j;
	n=80;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d%*c",&mat[i][j]);
	c(0,0,0);
	printf("%d\n",min);
}
