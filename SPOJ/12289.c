#include<stdio.h>
typedef long long int ll;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,x1,x2,y1,y2,dist;
		scanf("%lld%lld%lld%lld%lld",&a,&x1,&y1,&x2,&y2);
		if(y1==y2)
			dist = abs(x1-x2);
		else if(x1==x2)
			dist = abs(y1-y2);
		else if(y2)
		{
			dist = max();
		}
	}
	return 0;
}
