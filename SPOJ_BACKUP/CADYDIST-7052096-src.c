#include<stdio.h>
typedef unsigned long long int ull;
int insert(ull[], ull, ull);
ull delete_min(ull [],ull);
int main()
{
	ull i,n,j,x;
	scanf("%llu",&n);
	while(n)
	{
		n=n+1;
		ull a[n],b[n],c[n],d[n];
		ull total = 0;
		scanf("%llu",&a[1]);
		for(i=2;i<n;i++)
		{
			scanf("%llu",&x);
			insert(a,x,i);
		}
		scanf("%llu",&b[1]);
		for(i=2;i<n;i++)
		{
			scanf("%llu",&x);
			insert(b,x,i);
		}
		for(i=1;i<n;i++)
		{
			c[i] = delete_min(a,n-i);
			d[i] = delete_min(b,n-i);
		}
		for(i=1;i<n;i++)
			total += c[i] * d[n-i];		
		printf("%llu\n",total);
		scanf("%llu",&n);
	}
	return 0;
}
int insert(ull a[], ull x,ull index)
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
