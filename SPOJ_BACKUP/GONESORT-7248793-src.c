#include<stdio.h>
typedef long long int ll;
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ll lis=0,i,j,n,k;
		scanf("%lld",&n);
		ll a[n],b[n];
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
			b[j] = 1;
		}
		for(j=0;j<n;j++)
		{
			for(k=0;k<j;k++)
				if( ( a[j] == a[k]+1 ) && ( b[k]>= b[j] ) )
					b[j]=b[k]+1;
			if( b[j] > lis)
				lis=b[j];
		}
		printf("%lld\n",n-lis);
	}
	return 0;
}
