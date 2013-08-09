#include<stdio.h>
int main()
{
	while(1)
	{
		int n,m;
		scanf("%d",&n);
		if(n==0)
			break;
		int a[n],i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		int b[m],j=0,k;
		long long int sum1,sum2,pathsum=0;
		for(i=0;i<m;i++)
			scanf("%d",&b[i]);
		i=j=0;
		sum1 = sum2 = 0;
		while(1)
		{
			if(i==n || j==m)
			{
				if(i==n)
					for(k=j;k<m;k++)
						sum2+=b[k];
				if(j==m)
					for(k=i;k<n;k++)
						sum1+=a[k];
				pathsum += (sum1>sum2)?sum1:sum2;
				break;
			}
			if(a[i] == b[j])
			{
				sum1+=a[i];
				sum2+=b[j];
				pathsum += (sum1>sum2)?sum1:sum2;
				sum1 = 0;
				sum2 = 0;
				i++;
				j++;
			}
			else if(a[i] < b[j])
				sum1 += a[i++];
			else if(a[i] > b[j])
				sum2 += b[j++];
		}
		printf("%lld\n",pathsum);
	}
	return 0;
}
