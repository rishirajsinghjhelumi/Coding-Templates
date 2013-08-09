#include <stdio.h>
struct arr
{
	int data,index;
};
typedef struct arr arr;
int insert(arr [], int, int);
arr delete_min(arr [],int n);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int i,n,j,x;
		long long int count=0;
		scanf("%d",&n);
		n=n+1;
		arr a[n],b[n],c[n];
		if(n>=2)
		{
			scanf("%d",&a[1].data);
			a[1].index=1;
			c[1].data=a[1].data;
			c[1].index=a[1].index;
		}
		for(i=2;i<n;i++)
		{
			scanf("%d",&x);
			insert(a,x,i);
			c[i].data=x;
			c[i].index = i;
		}
		for(i=1;i<n;i++)
		{
			b[i] = delete_min(a,n-i);
			for(j=1;j<b[i].index;j++)
				if(b[i].data < c[j].data)
					count++;
		}
		printf("%lld\n",count);
	}
	return 0;
}
int insert(arr a[], int x,int index)
{
	int i,j,parent;
	arr temp;
	a[index].data = x;
	a[index].index = index;
	while(index!=1)
	{
		parent = index / 2;
		if(a[parent].data > a[index].data)
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
arr delete_min(arr a[],int n)
{
	int min,index,i,j;
	arr temp,t;
	t.data=a[1].data;
	t.index = a[1].index;
	a[1] = a[n];
	n = n - 1;
	index = 1;
	while(index<=n/2)
	{
		if(a[index].data < a[2*index].data && a[index].data < a[2*index+1].data)
			break;
		else
		{
			if(a[2*index].data < a[2*index+1].data)
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
	return t;
}
