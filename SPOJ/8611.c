#include<stdio.h>
int main()
{
	unsigned long long int a[65][10];
	int i,j;
	for(i=0;i<10;i++)
		a[0][i] = i+1;
	for(i=1;i<65;i++)
	{
		a[i][0] = 1;
		for(j=1;j<10;j++)
			a[i][j] = a[i][j-1] + a[i-1][j];
	}
	int test_cases;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		int n;
		scanf("%*d%d",&n);
		printf("%d %llu\n",i+1,a[n-1][9]);
	}
	return 0;
}
