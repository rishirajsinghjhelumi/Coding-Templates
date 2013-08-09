#include<stdio.h>
typedef long long int ll;
ll count=0,n,min;
void counter(ll x,ll y);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		count=0;
		counter(0,0);
		printf("%lld\n",count);
	}
}
void counter(ll x,ll y)
{
	if((x==0&&y==2)||(x==n/2&&(y==0||y==2||y==4))||(x==n-1&&y==2)||x>=n||y>4)
		return;
	if(x==n-1 && y==4)
	{
		count++;
		return;
	}
	counter(x+1,y);
	counter(x,y+1);
}
