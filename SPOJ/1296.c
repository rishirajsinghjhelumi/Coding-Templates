#include<stdio.h>
#include<algorithm>
#define max 4000
int a[max],b[max],c[max],d[max],ab[max*max],cd[max*max];
int main()
{
	int i,n,j,k=0,l,x1,x2,x;
	scanf("%d",&n);
	l = n*n;
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	unsigned long long int count= 0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			ab[k] = a[i] + b[j];
			cd[k++] = -1*(c[i] + d[j]);
		}
	std::sort(ab,ab+l);
	std::sort(cd,cd+l);
	i = j = 0;
	while(1)
	{
		if(i==l || j==l)
			break;
		if(ab[i] == cd[j])
		{
			x1 = x2 = 0;
			x = ab[i];
			while(ab[i]==x && i<l)
			{
				i++;
				x1++;
			}
			while(cd[j]==x && j<l)
			{
				j++;
				x2++;
			}
			count += x1*x2;
		}
		else if(ab[i] < cd[j])
			i++;
		else if(ab[i] > cd[j])
			j++;
	}
	printf("%llu\n",count);
	return 0;
}
