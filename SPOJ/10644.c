#include<stdio.h>
#define max 1000010
typedef long long int ull;
ull up[max],down[max],d[max],s[max],w[max];
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ull i,j,k,n,dist=0,dd,ud,sum=0,x,index,min;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&w[i]);
			sum += w[i];
			s[i] = sum;
		}
		for(i=0;i<n-1;i++)
			scanf("%lld",&d[i]);
		down[0] = 0;
		up[n-1] = 0;
		for(i=1;i<n;i++)
			down[i] = down[i-1] + s[i-1]*d[i-1];
		for(j=n-2;j>=0;j--)
			up[j] = up[j+1] + (s[n-1]-s[j])*d[j]*2;
		min = down[0]+up[0]+10;
		index=0;
		for(i=0;i<n;i++)
		{
			if(w[i])
				x = down[i] + up[i] + 10;
			else
				x = down[i]+up[i];
			if(x<min)
			{
				min = x;
				index = i;
			}
		}
		printf("%lld %lld\n",min,index+1);
	}
	return 0;
}
