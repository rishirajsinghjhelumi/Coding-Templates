#include<stdio.h>
typedef unsigned long long int ull;
ull gcd(ull a,ull b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	ull n;
	while(scanf("%llu",&n) && n!=-1)
	{
		ull x,y,x1=1,y1=1,i,g;
		for(i=0;i<n-1;i++)
		{
			scanf("%llu%llu",&x,&y);
			x1 *=x;
			y1 *=y;
		}
		g = gcd(x1,y1);
		x1 /=g;
		y1 /=g;
		printf("%llu %llu\n",x1,y1);
	}
	return 0;
}
