#include<stdio.h>
#include<algorithm>
#include<math.h>
typedef unsigned long long int ull;
ull p[1000000]={0},prime[1000000],a[1000000],b[1000000];
int main()
{
	ull i,j,k = 0;
	for(i=2;i<1000000;i++)
		if(p[i]==0)
		{
			prime[k++] = i;
			for(j=2*i;j<1000000;j=j+i)
				p[j] = 1;
		}
	int test_cases,t;
	scanf("%d",&test_cases);
	for(t=1;t<=test_cases;t++)
	{
		ull n,x,i,j=0,l=0,m=0,known[80000]={0};
		scanf("%llu",&n);
		for(i=0;i<n;i++)
		{
			scanf("%llu",&x);
			j=0;
			while(x!=1)
			{
				while(x%prime[j]==0)
				{
					x /=prime[j];
					known[j] = 1;
				}
				j++;
				if(j==k && x!=1)
				{
					b[m++] = x;
					break;
				}
			}
		}
		for(i=0;i<k;i++)
			if(known[i] == 1)
				a[l++] = prime[i];
		printf("Case #%d: %llu\n",t,m+l);
		for(i=0;i<l;i++)
			printf("%llu\n",a[i]);
		std::sort(b,b+m);
		for(i=0;i<m;i++)
			printf("%llu\n",b[i]);
	}
	return 0;
}
