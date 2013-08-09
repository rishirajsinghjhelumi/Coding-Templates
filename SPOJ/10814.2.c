#include<stdio.h>
typedef long long int ll;
ll count=0,n,min;
int a[100][100]={0};
void counter(ll x,ll y,ll l);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		count=0;
		counter(0,0,0);
		printf("%lld\n",count);
	}
}
void counter(ll x,ll y,ll l)
{
	if((x==0&&y==2)||(x==n/2&&(y==0||y==2||y==4))||(x==n-1&&y==2)||x>=n||y>4||a[x][y]||l>n+3)
		return;
	if(x==n-1 && y==4 && l==n+3)
	{
		count++;
		return;
	}
	a[x][y]=1;
	counter(x+1,y,l+1);
	counter(x,y+1,l+1);
	a[x][y]=0;
}
