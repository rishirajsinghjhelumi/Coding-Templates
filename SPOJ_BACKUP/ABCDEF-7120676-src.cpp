#include<stdio.h>
#include<algorithm>
#define INF 1<<30
long int a[100],ab[10000],ab_c[1000000],de_df[1000000],e_f[10000];
int main()
{
	int n;
	scanf("%d",&n);
	long int i,j,k,l=n*n,m=n*n*n,x1,x2,x;
	unsigned long long int count = 0;
	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
	k = 0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			ab[k] = a[i]*a[j];
			e_f[k++] = a[i]+a[j];
		}
	k = 0;
	for(i=0;i<l;i++)
		for(j=0;j<n;j++)
		{
			de_df[k] = (a[j]!=0)?e_f[i]*a[j]:INF;
			ab_c[k++] = ab[i]+a[j];
		}
	std::sort(ab_c,ab_c+m);
	std::sort(de_df,de_df+m);
	i = j = 0;
	while(1)
	{
		if(i==m || j==m)
			break;
		if(ab_c[i] == de_df[j])
		{
			x1 = x2 = 0;
			x = ab_c[i];
			while(ab_c[i]==x && i<m)
			{
				i++;
				x1++;
			}
			while(de_df[j]==x && j<m)
			{
				j++;
				x2++;
			}
			count += x1*x2;
		}
		else if(ab_c[i] < de_df[j])
			i++;
		else if(ab_c[i] > de_df[j])
			j++;
	}
	printf("%llu\n",count);
	return 0;
}
