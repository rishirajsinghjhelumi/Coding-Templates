#include<stdio.h>
int insert(int [], int, int);
int delete_min(int [],int n);
int main()
{
	int fibo[36],i;
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 2;
	for(i=3;i<36;i++)
		fibo[i] = fibo[i-1]+fibo[i-2];
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		int task[n+1],i,j,k,x,a[3],min;
		n++;
		for(i=1;i<n;i++)
		{
			scanf("%d",&x);
			k = bin_search(fibo,x);
			if(fibo[k] == x)
				insert(task,x,i);
			else
			{
				min = 0;
				a[0] = abs(fibo[k-1] - x);
				a[1] = abs(fibo[k] - x);
				a[2] = abs(fibo[k+1] - x);
				for(j=1;j<=2;j++)
					if(a[j] <= a[min])
						min = j;
				insert(task,fibo[k+min-1],i);
			}
		}
		for(i=1;i<n;i++)
			printf("%d ",delete_min(task,n-i));
		printf("\n");
	}
	return 0;
}
int bin_search(int fibo[],int x)
{
	int high=35,low = 0,mid;
	while(high>low)
	{
		mid = low+((high-low)>>1);
		if(fibo[mid] == x)
			break;
		else if(fibo[mid] > x)
			high = mid;
		else
			low = mid+1;
	}
	return mid;
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
/*			if(x==0)
			task[i] = 0;
			else if(x==1)
			task[i] = 1;
			else if(x==2)
			task[i] = 2;
			else if(x==3)
			task[i] = 3;
			else if(x>=4 && x<=6)
			task[i] = 5;
			else if(x>=7 && x<=10)
			task[i] = 8;
			else if(x>=11 && x<=16)
			task[i] = 13;
			else if(x>=17 && x<=27)
			task[i] = 21;*/
