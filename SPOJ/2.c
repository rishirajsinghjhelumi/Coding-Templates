#include<stdio.h>
#include<math.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int j,k=0,check=0,l;
		long int n,m,a[100000],i;
		scanf("%ld%ld",&n,&m);
		a[k++] = 2;
		if(a[k-1]>=n)
			printf("%ld\n",a[k-1]);
		for(i=3;i<=m;i++)
		{
			check=0;
			for(j=0;j<k;j++)
				if(i % a[j] == 0)
				{
					check = 1;
					break;
				}
			if(check==0)
			{
				a[k++] = i;
				if(a[k-1] >=n)
					printf("%ld\n",a[k-1]);
			}
		}
	}
	return 0;
}
