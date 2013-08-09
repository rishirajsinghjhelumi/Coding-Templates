#include<stdio.h>
char a[100][100];
int min = 0;
int steper(int n ,int i, int j ,int steps);
int main()
{
	int n,i,j,steps=0;
	scanf("%d%*c",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%c",&a[i][j]);
		scanf("%*c");
	}
	steper(n,0,0,0);
	printf("%d",min);
	return 0;
}
int steper(int n ,int i, int j ,int steps)
{
	if(i==n-1 && j==n-1)
	{
		min++;
		return;
	}
	if(i+a[i][j]-48 < n && a[i][j]-48 > 0)
		steper(n,i+a[i][j]-48,j,steps+1);
	if(j+a[i][j]-48 < n && a[i][j]-48 > 0)
		steper(n,i,j+a[i][j]-48,steps+1);
	return;
}
