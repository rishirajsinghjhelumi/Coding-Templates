#include<stdio.h>
#include<algorithm>
#include<assert.h>
typedef unsigned long long int ull;
using namespace std;
ull a[1000010];
ull gcd(ull a,ull b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		char s1[100],s2[100];
		ull n,g1=0,x,b=1000000000,i,d=0;
		b *=b;
		scanf("%s%s%llu",s1,s2,&n);
		for(i=0;i<n;i++)
			scanf("%llu",&a[i]);
		sort(a,a+n);
		i=0;
		if(n!=1)
		{
			while(1)
			{
				x = a[i+1] - a[i];
				if(x)
				{
					g1 = x;
					i++;
					d = 1;
					break;
				}
				if(++i==n-1)
					break;
			}
			for(;i<n-1;i++)
			{
				x = a[i+1] - a[i];
				if(x)
					g1 = gcd(g1,x);
			}
		}
		if(g1<=b && d==1)
			printf("%s %s %llu\n",s1,s2,g1);
		else
			printf("%s %s I can't count that high\n",s1,s2);
	}
	return 0;
}
