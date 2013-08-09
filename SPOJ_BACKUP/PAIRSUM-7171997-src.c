#include<stdio.h>
#define max 1000010
typedef unsigned long long int ull;
ull s[max],p[max];
int main()
{
	ull n,m,u,v,i,j,x,sum = 0,prod=0,ans;
	scanf("%llu",&n);
	for(i=0;i<n;i++)
	{
		scanf("%llu",&x);
		sum += x;
		s[i] = sum;
		prod += sum*x;
		p[i] = prod;
	}
	scanf("%llu",&m);
	while(m--)
	{
		scanf("%llu%llu",&u,&v);
		if(u)
			ans = (p[v] - p[u-1])- s[u-1]*(s[v]-s[u-1]);
		else
			ans = p[v];
		printf("%llu\n",ans);
	}	
	return 0;
}
