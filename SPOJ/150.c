#include<stdio.h>
#include<algorithm>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,i,j;
		scanf("%d",&n);
		int x[n],y[n],sumx[n],sumy[n],sx=0,sy=0,sumx2[n],sumy2[n],ssx=0,ssy=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			ssx+=x[i];
			ssy+=y[i];
		}
		std::sort(x,x+n);
		std::sort(y,y+n);
		for(i=0;i<n;i++)
		{
			printf("%d ",x[i]);
			sumx[i] = sx;
			sumx2[i] = ssx - sx - x[i];
			sx+=x[i];
		}
		printf("\n");
		for(i=0;i<n;i++)
			printf("%d ",sumx[i]);
		printf("\n");
		for(i=0;i<n;i++)
			printf("%d ",sumx2[i]);
		printf("\n");
		for(i=0;i<n;i++)
		{
			printf("%d ",y[i]);
			sumy[i]=sy;
			sumy2[i] = ssy - sy -y[i];
			sy+=y[i];
		}
		printf("\n");
		for(i=0;i<n;i++)
			printf("%d ",sumy[i]);
		printf("\n");
		for(i=0;i<n;i++)
			printf("%d ",sumy2[i]);
		printf("\n");
	}
	return 0;
}
