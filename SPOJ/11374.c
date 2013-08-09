#include<stdio.h>
int main()
{
	int test_cases,t;
	scanf("%d",&test_cases);
	for(t=1;t<=test_cases;t++)
	{
		int n,m,i,j,x1,x2,poss=1;
		scanf("%d%d",&n,&m);
		int a[n][9000];
		for(i=0;i<n;i++)
			for(j=0;j<9000;j++)
				a[i][j] = 0;
		while(m--)
		{
			scanf("%d%d",&x1,&x2);
			if(a[x1-1][x2-1000] == 1)
				poss = 0;
			else
				a[x1-1][x2-1000] = 1;
		}
		printf("Scenario #%d: %s\n",t,(poss==1)?"possible":"impossible");
	}
	return 0;
}
