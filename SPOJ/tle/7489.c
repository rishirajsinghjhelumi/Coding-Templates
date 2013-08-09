#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,i,j,check=0,sec=0;
		unsigned long long int k,m,sum=0,count=0;
		scanf("%d%llu%llu",&n,&k,&m);
		int a[n][n];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
				sum+=a[i][j];
				if(a[i][j] >= k)
					check = 1;
			}
		if(check==0)
		{
			printf("Not possible\n");
			continue;
		}
		if(sum>=m)
		{
			printf("0\n");
			continue;
		}
		while(sum<m)
		{
			sec++;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					count=0;
					if(a[i][j] >= k)
					{
						a[i][j]++;
						count++;
						if(i-1>=0)
						{
							a[i-1][j]++;
							count++;
						}
						if(i+1<n)
						{
							a[i+1][j]++;
							count++;
						}
						if(j-1>=0)
						{
							a[i][j-1]++;
							count++;
						}
						if(j+1<n)
						{
							a[i][j+1]++;
							count++;
						}
					}
					sum+=count;
					if(sum>=m)
						break;
				}
				if(sum>=m)
					break;
			}
		}
		printf("%d\n",sec);
	}
	return 0;
}
