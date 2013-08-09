#include<stdio.h>
#include<stdlib.h>
struct arr
{
	int data,u,v;
};
typedef struct arr arr;
int insert(arr [], int, int,int ,int);
arr delete_min(arr [],int n);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int i=0,j=0,k,n,weight,edge=0,u,v,w,cu=0,cv=0,e,p;
		scanf("%d%d%d",&p,&n,&e);
		e=e+1;
		arr a[e],b[e];
		int parent[n+1],color[n+1];
		for(i=1;i<=n;i++)
			parent[i] = color[i] = 0;
		scanf("%d%d%d",&a[1].u,&a[1].v,&a[1].data);
		for(i=2;i<e;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			insert(a,w,i,u,v);
		}
		long long int weigh=0;
		i=1;
		while(edge!=n-1)
		{
			b[i] = delete_min(a,e-i);
			if(color[b[i].u]==1 && color[b[i].v]==1 && parent[b[i].u] == parent[b[i].v])
			{
				i++;
				continue;
			}
			else
			{
				weigh+=b[i].data;
				if(color[b[i].u]==0 && color[b[i].v]==0)
				{
					color[b[i].u] = color[b[i].v] = 1;
					parent[b[i].u] = parent[b[i].v] = b[i].u;
				}
				else if(color[b[i].u]==0 && color[b[i].v]==1)
				{
					color[b[i].u] = 1;
					parent[b[i].u] = parent[b[i].v];
				}
				else if(color[b[i].v]==0 && color[b[i].u]==1)
				{
					color[b[i].v] = 1;
					parent[b[i].v] = parent[b[i].u];
				}
				else
				{
					for(i=1;i<n+1;i++)
						if(parent[i] == parent[b[i].v])
							parent[i] = parent[b[i].u];
				}
				edge++;
				i++;
			}
		}
		printf("%lld\n",weigh*p);
	}
	return 0;
}
int insert(arr a[], int x,int index,int u,int v)
{
	int i,j,parent;
	arr temp;
	a[index].data = x;
	a[index].u=u;
	a[index].v=v;
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
	t.u=a[1].u;
	t.v=a[1].v;
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
