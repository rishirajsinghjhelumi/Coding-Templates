#include <stdio.h>
int insert(int [], int, int);
int delete_min(int [],int n);
int main()
{
	int i,n,j,x;
	scanf("%d",&n);
	n=n+1;
	int a[n],b[n];
	scanf("%d",&a[1]);
	for(i=2;i<n;i++)
	{
		scanf("%d",&x);
		insert(a,x,i);
	}
	for(i=1;i<n;i++)
		printf("%d\n",delete_min(a,n-i));
	return 0;
}
int insert(int a[], int x,int index)
{
	int i,j,parent,temp;
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
int delete_min(int a[],int n)
{
	int min,index,i,j,temp;
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
