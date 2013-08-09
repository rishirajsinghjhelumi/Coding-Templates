#include<stdio.h>
int main()
{
	int n,m,i,j,temp;
	scanf("%d%d",&n,&m);
	int a[n][m];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(j==0)
				a[i][j] += a[i-1][j] > a[i-1][j+1]?a[i-1][j+1]:a[i-1][j];
			else if(j==m-1)
				a[i][j] += a[i-1][j] > a[i-1][j-1]?a[i-1][j-1]:a[i-1][j];
			else
			{
				temp = a[i-1][j] > a[i-1][j+1]?a[i-1][j+1]:a[i-1][j];
				if(a[i-1][j-1] < temp)
					temp = a[i-1][j-1];
				a[i][j] += temp;
			}
		}
	int max=a[n-1][0];
	for(i=1;i<m;i++)
		if(a[n-1][i] < max)
			max = a[n-1][i];
	printf("%d\n",max);
	return 0;
}
