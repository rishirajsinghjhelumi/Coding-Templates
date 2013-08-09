#include<stdio.h>
#include<algorithm>
#define max 1000010
typedef unsigned long long int ull;
using namespace std;
ull a[max];
int main()
{
	ull n,m,sum=0,i,k=1,ans=-1,x;
	scanf("%llu%llu",&n,&m);
	for(i=0;i<n;i++)
		scanf("%llu",&a[i]);
	sort(a,a+n);
	while(n--)
	{
		sum+=a[n];
		if(sum>=m)
		{
			x = (sum - m)/k;
			if(x>ans || ans==-1)
				ans = x;
		}
		k++;
	}
	printf("%llu\n",ans);
	return 0;
}

