#include <stdio.h>
int insert(int [], int, int);
int delete_min(int [],int n);
int main()
{
	int i,n,j,x,count=0,k,l;
	scanf("%d",&n);
	n=n+1;
	int a[4][n],b[4][n];
	scanf("%d",&a[0][1]);
	scanf("%d",&a[1][1]);
	scanf("%d",&a[2][1]);
	scanf("%d",&a[3][1]);
	for(i=2;i<n;i++)
	{
		scanf("%d",&x);
		insert(a[0],x,i);
		scanf("%d",&x);
		insert(a[1],x,i);
		scanf("%d",&x);
		insert(a[2],x,i);
		scanf("%d",&x);
		insert(a[3],x,i);
	}
	for(i=1;i<n;i++)
	{
		b[0][i] = delete_min(a[0],n-i);
		b[1][i] = delete_min(a[1],n-i);
		b[2][i] = delete_min(a[2],n-i);
		b[3][i] = delete_min(a[3],n-i);
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			for(k=1;k<n;k++)
			{
				for(l=1;l<n;l++)
				{
					if(b[3][l] > -1*(b[0][i]+b[1][j]+b[2][k]))
						break;
					if(b[0][i]+b[1][j]+b[2][k]+b[3][l] == 0)
						count++;
				}
			}
		}
	}
	printf("%d\n",count);
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
