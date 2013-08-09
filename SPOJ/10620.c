#include<stdio.h>
#include<algorithm>
#define max 300010
typedef long long int ll;
ll a[max],b[max],c[max];
ll b_search(ll *c,ll len,ll x);
int main()
{
	ll lis=0,i,j,n,k;
	scanf("%lld",&n);
	ll a[n],b[n];
	for(j=0;j<n;j++)
		scanf("%lld",&a[j]);
	c[0] = a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<c[0])
		{
			c[0] = a[i];
			b[i] = 1;
		}
		else if(a[i]>c[lis])
		{
			lis++;
			c[lis] = a[i];
			b[i] = lis;
		}
		else
		{
			k = b_search(c,lis,a[i]);
			c[k] = a[i];
			b[i] = k;
		}
	}
	printf("%lld\n",n-lis);
	return 0;
}
ll b_search(ll *c,ll len,ll x)
{
	ll low=0,high=len-1,mid;
	while(high>low)
	{
		mid = (high+low)>>1;
		if(c[mid] > x)
			high = mid-1;
		else
			low = mid + 1;
	}
	return mid;
}
