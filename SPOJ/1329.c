#include<stdio.h>
void summer(int s,int c,int es,int ec);
int x[500][500];
unsigned long long int count = 0;
int a,b,n,m;
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&x[i][j]);
	scanf("%d%d",&a,&b);
	summer(0,0,n-1,m-1);
	printf("%llu\n",count);
	return 0;
}
int xx=0;
void summer(int s,int c,int es,int ec)
{
	if(es<s || ec<c)
		return;
	int i,j,sum = 0;
	printf("Considering Matrix No.:->%d\n",++xx);
	for(i=s;i<=es;i++)
	{
		for(j=c;j<=ec;j++)
			printf("%d ",x[i][j]);
		printf("\n");
	}
	for(i=s;i<=es;i++)
		for(j=c;j<=ec;j++)
			sum += x[i][j];
	if(sum>=a && sum<=b)
		count++;
	for(i=s;i<es;i++)
		summer(s,c,i,ec);
	for(i=c;i<ec;i++)
		summer(s,c,es,i);
}
