#include<stdio.h>
#include<string.h>
void print(int a[] ,int n);
void insert(int a[],int b[],int x,int y ,int n);
void delete(int a[],int x,int y ,int n);
void reverse(int a[] ,int x ,int y);
long long int get_sum(int a[],int x,int y);
void make_same(int a[] ,int x ,int y ,int z);
long long int max_sum(int a[],int n);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,m,i,j,x,y,z;
		scanf("%d%d",&n,&m);
		int a[500000];
		char str[30];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<m;i++)
		{
			//print(a,n);
			scanf("%s",str);
			if(strcmp(str,"GET-SUM")==0)
			{
				scanf("%d%d",&x,&y);
				printf("%lld\n",get_sum(a,x,y));
			}
			else if(strcmp(str,"MAX-SUM")==0)
			{
				printf("%lld\n",max_sum(a,n));
			}
			else if(strcmp(str,"REVERSE")==0)
			{
				scanf("%d%d",&x,&y);
				reverse(a,x,y);
			}
			else if(strcmp(str,"DELETE")==0)
			{
				scanf("%d%d",&x,&y);
				if(y>n-x)
					y=n-x+1;
				delete(a,x,y,n);
				n=n-y;
			}
			else if(strcmp(str,"INSERT")==0)
			{
				scanf("%d%d",&x,&y);
				int b[y];
				for(j=0;j<y;j++)
					scanf("%d",&b[j]);
				insert(a,b,x,y,n);
				n=n+y;
			}
			else if(strcmp(str,"MAKE-SAME")==0)
			{
				scanf("%d%d%d",&x,&y,&z);
				make_same(a,x,y,z);
			}
		}
	}
	return 0;
}
long long int max_sum(int a[],int n)
{
	int i,j,max=-999999,k,sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=0;
			for(k=i;k<=j;k++)
				sum+=a[k];
			if(sum > max)
				max=sum;
		}
	}
	return max;
}
long long int get_sum(int a[],int x,int y)
{
	int i,sum=0;
	for(i=x-1;i<x+y-1;i++)
		sum += a[i];
	return sum;
}
void make_same(int a[] ,int x ,int y ,int z)
{
	int i;
	for(i=x-1;i<x+y-1;i++)
		a[i] = z;
}
void reverse(int a[] ,int x ,int y)
{
	int i,temp;
	for(i=0;i<y/2;i++)
	{
		temp = a[x+i-1];
		a[x+i-1] = a[x+y-i-2];
		a[x+y-i-2] = temp;
	}
}
void delete(int a[],int x,int y ,int n)
{
	int i;
	for(i=x-1;i<n-y;i++)
		a[i] = a[i+y];
}
void insert(int a[],int b[],int x,int y ,int n)
{
	int i;
	for(i=n-1;i>=x;i--)
		a[i+y] = a[i];
	for(i=x;i<x+y;i++)
		a[i] = b[i-x];
}
void print(int a[] ,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
