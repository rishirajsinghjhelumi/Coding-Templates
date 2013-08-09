#include<stdio.h>
int insert(int [], int, int);
int delete_min(int [],int n);
int main()
{
	int i,n,j,x,m;
	scanf("%d%d",&m,&n);
	n=n+1;
	int a[n],b[n];
	long long int anger=0,candy=0,total=0,more=0,extras=0;
	scanf("%d",&a[1]);
	candy+=a[1];
	for(i=2;i<n;i++)
	{
		scanf("%d",&x);
		insert(a,x,i);
		candy+=x;
	}
	total = (candy-m)/(n-1);
	extras = (candy-m)%(n-1);
	x=0;
	for(i=1;i<n;i++)
	{
		b[i] = delete_min(a,n-i);
		if(b[i] < total)
		{
			anger += b[i]*b[i];
			more +=b[i];
			x++;
		}
		else 
			break;
	}
	x=n-1-x;
	total = (total*(n-1)+extras)-more;
	extras = (total)%(x);
	total = total/(x);
	if(extras==0)
		anger += total*total*(x);
	else
	{
		anger += (total+1)*(total+1)*extras;
		x=x-extras;
		anger += total*total*(x);
	}
	printf("%lld\n",anger);
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
