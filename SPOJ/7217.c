#include<stdio.h>
int main()
{
	int n,m,x,y,i,j,max;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	int a[n][m];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for(i=y;i<m;i++)
		a[x-1][i] = a[x-1][i-1] - a[x-1][i];
	for(i=x;i<n;i++)
		a[i][y-1] = a[i-1][y-1] - a[i][y-1];
	for(i=x;i<n;i++)
		for(j=y;j<m;j++)
		{
			max = a[i][j-1]>a[i-1][j]?a[i][j-1]:a[i-1][j];
			a[i][j] = max - a[i][j];
		}
	if(a[n-1][m-1] >= 0 )
		printf("Y %d\n",a[n-1][m-1]);
	else
		printf("N\n");
	return 0;
}
