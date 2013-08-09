#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,i,j=0,k,l=0,sum=0,x,a[1000000];
		unsigned long long int count=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&a[j++]);
			sum += a[j-1];
			if(sum == 47)
			{
				count++;
				sum -= a[l++];
			}
			else if(sum>47)
			{
				while(sum>47)
				{
					sum -= a[l++];
					if(sum == 47)
						count++;
				}
			}
		}
		printf("%llu\n",count);
	}
	return 0;
}

