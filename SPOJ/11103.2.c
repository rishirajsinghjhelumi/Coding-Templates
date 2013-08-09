#include<stdio.h>
#include<math.h>
typedef unsigned long long int ull;
ull insert(ull [], ull, ull);
ull delete_min(ull [],ull n);
ull p[1000000]={0},prime[1000000];
int main()
{
	ull i,j,k = 0;
	for(i=2;i<1000000;i++)
		if(p[i]==0)
		{
			prime[k++] = i;
			for(j=2*i;j<1000000;j=j+i)
				p[j] = 1;
		}
	int test_cases,t;
	scanf("%d",&test_cases);
	for(t=1;t<=test_cases;t++)
	{
		ull n,x,i,j=0,l=0;
		scanf("%llu",&n);
		n++;
		ull num[n],num_sorted[n],a[n];
		scanf("%llu",&num[1]);
		for(i=2;i<n;i++)
		{
			scanf("%llu",&x);
			insert(num,x,i);
		}
		for(i=1;i<n;i++)
			num_sorted[i] = delete_min(num,n-i);
		i=1;
		printf("Case #%d: %llu\n",t,l);
		for(i=0;i<l;i++)
			printf("%llu\n",a[i]);
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
