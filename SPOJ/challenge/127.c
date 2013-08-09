#include <stdio.h>
struct arr
{
	long long int data;
	int index;
};
typedef struct arr arr;
int insert(arr [], long long int, int);
arr delete_min(arr [],int n);
int main()
{
	long long int count=0,avg,summer=0;
	long long int x;
	int n,i;
	scanf("%d",&n);
	n=n+1;
	arr a[n],b[n],c[n];
	if(n>=2)
	{
		scanf("%lld",&a[1].data);
		a[1].index=1;
		count+=a[1].data;
	}
	for(i=2;i<n;i++)
	{
		scanf("%lld",&x);
		insert(a,x,i);
		count+=x;
	}
	for(i=1;i<n;i++)
	{
		b[i] = delete_min(a,n-i);
		summer+=b[i].data;
		if(summer <= count-summer)
			printf("%d\n",b[i].index);
		else
		{
			if(check_difference(summer,count-summer)==1)
				printf("%d\n",b[i].index);
			break;
		}
	}
	return 0;
}
int check_difference(long long int a,long long int b)
{
	int i;
	if(a==b)
		return 0;
	else
	{
		for(i=1;i<=100;i++)
		{
			if(a-b==i)
				return 1;
		}
	}
	return 0;
}
int insert(arr a[], long long int x,int index)
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
	int index,i,j;
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
