#include<stdio.h>
#include<math.h>
int i,p[2000000]={0},j,prime[1000000],k=0;
unsigned long long int sum =0;
int main()
{
	for(i=2;i<2000000;i++)
		if(p[i]==0)
		{
			sum+=i;
			for(j=2*i;j<2000000;j=j+i)
				p[j] = 1;
		}
	printf("%lld\n",sum);
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,m,i,j,l,x;
		scanf("%d%d",&m,&n);
		int a[n-m+1];
		for(i=0;i<n-m+1;i++)
			a[i] = m+i;
		for(i=0;i<n-m+1;i++)
		{
			if(a[i])
			{
				for(j=0;prime[j] < a[i]/2;j++)
				{
					if(a[i]%prime[j]==0)
					{
						for(l=i;l<n-m+1;l+=prime[j])
							a[l] = 0;
						break;
					}
					if(j==k-1)
						break;
				}
			}
		}
		if(m==1)
			a[0] = 0;
		for(i=0;i<n-m+1;i++)
			if(a[i])
				printf("%d\n",a[i]);
	}
	return 0;
}
