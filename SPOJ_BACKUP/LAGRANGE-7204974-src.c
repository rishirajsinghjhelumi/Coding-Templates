#include<stdio.h>
#include<math.h>
#define max (1<<15)+2
int ans[max],limit[max];
int main()
{
	int i,j;
	for(i=0;i<=max;i++)
	{
		ans[i] = 0;
		limit[i] = floor(sqrt(max - i) + 1);
	}
	int n;
	counter(1,0,0);
	while(scanf("%d",&n) && n)
		printf("%d\n",ans[n]);
	return 0;
}
int counter(int start,int s,int l)
{
	int i,j;
	if(s>=max)
		return;
	ans[s]++;
	if(l==4)
		return;
	for(i=start;i<limit[s];i++)
		counter(i,s+i*i,l+1);
	return;
}
