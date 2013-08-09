#include<stdio.h>
#define max 1000010
int a[max],count[max];
int main()
{
	int i,j,n,q,t,a,b;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
		count[i] = i+1;
	while(q--)
	{
		scanf("%d%d%d",&t,&a,&b);
		if(!t)
		{
			for(i=a;i<=b;i++)
			{
				a[i]++;
				if(!(a[i]%3))
					count[i]++;
			}
		}
	}
	return 0;
}
