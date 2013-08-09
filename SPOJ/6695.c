#include<stdio.h>
int sort(int [],int );
int calc_h_index(int [],int,int);
int h_index=0;
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int j,k,count,l,i;
		scanf("%d",&k);
		int num_papers[k];
		for(i=0;i<k;i++)
			scanf("%d",&num_papers[i]);
		sort(num_papers,k);
		if(k%2==0)
		{
			calc_h_index(num_papers,0,k/2);
			calc_h_index(num_papers,k/2,k);
		}
		else
		{
			calc_h_index(num_papers,0,k/2+1);
			calc_h_index(num_papers,k/2+1,k);
		}
		printf("%d\n",h_index);
		h_index=0;
	}
	return 0;
}
int calc_h_index(int a[],int low,int high)
{
	if(high-1 == low)
	{
		if(a[low] > h_index)
			h_index = h_index + 1;
		return;
	}
	if(a[high-1] > h_index)
	{
		h_index = h_index + high - low;
		return;
	}
	if(a[low] < h_index)
		return;
	if(a[high-1] <= h_index)
	{
		calc_h_index(a,low,(high+low)/2);
		calc_h_index(a,(high+low)/2,high);
	}
}
int sort(int a[],int n)
{
	int i,k,temp;
	for(k=1;k<n;k++)
	{   
		temp = a[k];
		i = k-1;
		while(temp > a[i] && i>=0)
		{   
			a[i+1] = a[i];
			i--;
		}   
		a[i+1] = temp;
	}   
}
