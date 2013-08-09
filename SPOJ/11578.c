#include<stdio.h>
typedef unsigned long long int ull;
ull insert(ull [], ull, ull);
ull delete_min(ull [],ull n);
int main()
{
	ull i,n,j,x,t=1;
	while(scanf("%llu",&n)!=EOF)
	{
		n=n+1;
		ull a[n],b[n],count=0;
		scanf("%llu",&a[1]);
		for(i=2;i<n;i++)
		{
			scanf("%llu",&x);
			insert(a,x,i);
		}
		j=delete_min(a,n-1);
		if(j!=0)
			count++;
		for(i=2;i<n;i++)
		{
			x = delete_min(a,n-i);
			if(x!=j)
			{
				j=x;
				count++;
			}
		}	
		printf("Case %llu: %llu\n",t++,count);
	}
	return 0;
}
ull insert(ull a[], ull x,ull index)
{
	ull i,j,parent,temp;
	a[index] = x;
	while(index!=1)
	{
		parent = index / 2;
		if(a[parent] > a[index])
		{
			temp = a[parent];
			a[parent] = a[index];
			a[index] = temp;
			index = parent;
		}
		else
			break;
	}
}
ull delete_min(ull a[],ull n)
{
	ull min,index,i,j,temp;
	min = a[1];
	a[1] = a[n];
	n = n - 1;
	index = 1;
	while(index<=n/2)
	{
		if(a[index] < a[2*index] && a[index] < a[2*index+1])
			break;
		else
		{
			if(a[2*index] < a[2*index+1])
			{
				temp = a[index];
				a[index] = a[2*index];
				a[2*index] = temp;
				index = 2*index;
			}
			else
			{
				temp = a[index];
				a[index] = a[2*index+1];
				a[2*index+1] = temp;
				index = 2*index+1;
			}
		}
	}
	return min;
}
