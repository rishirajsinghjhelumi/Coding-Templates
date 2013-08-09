#include<stdio.h>
#define max 125000
typedef long long int ull;
ull t[2*max],sum[2*max],s[2*max];
int main()
{
	t[1] = s[1] = sum[1] = 1;
	ull i,j=2,k=2,times=2;
	while(j<=max)
	{
		while(times--)
		{
			t[j] = k;
			sum[j] = sum[j-1] + j*k;
			s[j] = s[j-1] + k;
			j++;
		}
		times = t[++k];
	}
	ull test_cases,n;
	scanf("%lld",&test_cases);
	while(test_cases--)
	{
		scanf("%lld",&n);
		ull count,j=1,ans;
		while(sum[j]<n)j++;
		count = n - sum[--j];
		ans = count/(j+1) + (count%(j+1)?1:0);
		printf("%lld\n",ans+s[j]);
	}
	return 0;
}
