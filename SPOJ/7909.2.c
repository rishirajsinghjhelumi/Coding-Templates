#include<stdio.h>
#include<algorithm>
#include<math.h>
typedef long long int ull;
ull a[15],n,m,i,done,minc,count,fact[100],ind[100],y,p[10000];
void path(ull x,ull steps);
int main()
{
	while(scanf("%lld%lld",&n,&m)>0)
	{
		for(i=0;i<m;i++)
			scanf("%lld",&a[i]);
		std::sort(a,a+m);
		done=0;
		minc=-1;
		y=0;
		path(n,0);
		printf("%lld\n",minc);
		if(minc!=-1)
		{
			for(i=0;i<y;i++)
				printf("%lld ",p[i]);
			printf("\n");
		}
	}
}
void path(ull x,ull steps)
{
	if(x==0)
		return;
	if(x==1)
	{
		done=1;
		minc = steps;
		p[y++]=x;
		return;
	}
	ull k;
	for(k=m-1;k>=0;k--)
	{
		if(a[k]>1 && x%a[k]==0)
			path(x/a[k],steps+1);
		if(done)
		{
			p[y++]=x;
			return;
		}
	}
}
