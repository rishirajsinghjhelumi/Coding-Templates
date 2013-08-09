#include<stdio.h>
typedef long long int ll;
ll a[20],c[20],diff[20][20];
int main()
{
	ll t,d,i,j,k;
	for(i=0;i<20;i++)
		diff[0][i] = 1;
	for(i=1;i<20;i++)
	{
		for(j=0;j<i;j++)
			diff[i][j] = 0;
		for(j=i,k=1;j<20;j++)
			diff[i][j] = k++*diff[i-1][j];
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&d);
		for(i=0;i<=d;i++)
			scanf("%lld",&c[i]);
		a[d+1] = c[d]/(d+1);
		for(i=d-1;i>=0;i--)
		{
			ll s1=0;
			for(j=i;j<=d;j++)
				s1 += diff[i][j]*c[j];
			for(j=i+2;j<=d+1;j++)
				s1 -= diff[i][j]*a[j];
			a[i+1] = s1/diff[i][i+1];
		}
		for(i=1;i<=d;i++)
			printf("%lld ",a[i]);
		printf("%lld\n",a[d+1]);
	}
	return 0;
}
