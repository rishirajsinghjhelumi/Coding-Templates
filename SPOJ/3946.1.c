#include <stdio.h>
int insert(int [], int, int);
int delete_min(int [],int n);
int main()
{
	int i,n,j,m,x,y,z,f;
	scanf("%d%d",&n,&m);
	n=n+1;
	int a[n];
	for(i=1;i<n;i++)
		scanf("%d",&a[i]);
	while(m--)
	{
		scanf("%d%d%d",&x,&y,&z);
		int b[y-x+1];
		b[1] = a[x];
		for(i=x+1;i<=y;i++)
			insert(b,a[i],i-x+1);
		for(i=1;i<=z;i++)
			f=delete_min(b,(y-x+1)-i+1);
		printf("%d\n",f);
	}
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
