#include<stdio.h>
#include<algorithm>
#define max 1000010
typedef long long int ull;
using namespace std;
ull a[max];
ull input()
{
	register char c = getchar_unlocked();
	ull x=0;
	while(c>=48 && c<=57)
	{
		x = (x<<3)+(x<<1)+c-48;
		c = getchar_unlocked();
	}
	return x;
}
int main()
{
	ull n,m,sum=0,i,k=0,ans=-1,x;
	n = input();
	m = input();
	for(i=0;i<n;i++)
		a[i] = input();
	sort(a,a+n);
	while(n--)
	{
		sum+=a[n];
		k++;
		if(sum>=m)
			break;
	}
	while(n-->=0)
	{
		x = (sum-m)/k++;
		if(x>ans)
			ans = x;
		sum+=a[n];
	}
	printf("%llu\n",ans);
	return 0;
}
