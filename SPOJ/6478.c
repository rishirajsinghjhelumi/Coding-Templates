#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
typedef struct plane
{
	int x,y1,y2;
}arr;
int compare(const void *a,const void *b)
{
	return ( (*(arr **)a)->x - (*(arr **)b)->x );
}
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int i,j,k,n,v;
		long double angle,r,h,g=10.0;
		scanf("%d%d",&v,&n);
		arr data[n];
		for(i=0;i<n;i++)
			scanf("%d%d%d",&data[i].x,&data[i].y1,&data[i].y2);
		qsort(data,n,sizeof(data),compare);
		for(i=0;i<n;i++)
			printf("%d %d %d\n",data[i].x,data[i].y1,data[i].y2);
	}
	return 0;
}
