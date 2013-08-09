#include<stdio.h>
typedef long long int ll;
ll absurdity(ll n)
{
	ll r,len=0;
	while(1)
	{
		r = n % 10;
		if(r)
			break;
		n /= 10;
	}
	while(n)
	{
		n /=10;
		len++;
	}
	return (r==5)?2*len-1:2*len;
}
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ll n,abs,l1,l2,i,d=0;
		scanf("%lld",&n);
		abs = absurdity(n);
		l1 = (19*n)/20;
		l2 = (21*n)/20;
		if(n%20)
			l1++;
	}
	return 0;
}
