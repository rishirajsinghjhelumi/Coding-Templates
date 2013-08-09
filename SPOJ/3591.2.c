#include<stdio.h>
#include<math.h>
int n,i,j,count=0,c[1000010]={0},known[1000010];
int main()
{
	for(i=0;i<1000010;i++)
		known[i] = -1;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c[a[i]]++;
	}
	for(i=0;i<n;i++)
	{
		if(known[a[i]] == -1)
		{
			count = 0;
			int b=sqrt(a[i]);
			for(j=1;j<=b;j++)
				if(a[i]%j==0)
					count +=(j*j!=a[i])?c[j] + c[a[i]/j]:c[j];
			known[a[i]] = count-1;
			printf("%d\n",count-1);
		}
		else
			printf("%d\n",known[a[i]]);
	}
	return 0;
}
