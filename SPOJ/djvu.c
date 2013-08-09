#include<stdio.h>
#define max 10500000
#define max2 1000000
typedef long long int ull;
ull t[max+1000],sum[max+1000],s[max+1000];
ull res[max+10];
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
	j = 1;
	for(i=1;i<=max2;i++)
	{
		ull n = i*i*i;
		ull count,ans;
		while(sum[j]<n)j++;
		j--;
		count = n - sum[j];
		ans = count/(j+1) + (count%(j+1)?1:0);
		res[i] = res[i-1] + ans+s[j];
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x;
		scanf("%d",&x);
		printf("%lld\n",res[x]);
	}
	return 0;
}
