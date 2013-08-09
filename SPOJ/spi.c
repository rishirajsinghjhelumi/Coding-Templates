#include"stdio.h"
int main()
{
	int a[1000][1000],n,i,j,h,c=1;
	scanf("%d",&n);
	c=n*n;
	for(h=0;h<n/2;h++)
	{
		for(i=h;i<n-h;i++)
			a[h][i]=c--;
		for(i=h+1;i<n-h;i++)
			a[i][n-h-1]=c--;
		for(i=n-h-1-1;i>=h;i--)
			a[n-h-1][i]=c--;
		for(i=n-h-1-1;i>h;i--)
			a[i][h]=c--;
	}
	if(n%2!=0)
		a[(n/2)][(n/2)]=c--;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
