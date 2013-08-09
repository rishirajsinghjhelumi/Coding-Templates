#include<stdio.h>
int sort(int [],int );
int h_index=0;
int main()
{
	int k;
	scanf("%d",&k);
	while(k!=0)
	{
		int j,count,l,i;
		int num_papers[k];
		for(i=0;i<k;i++)
			scanf("%d",&num_papers[i]);
		sort(num_papers,k);
		for(j=1;j<=k;j++)
		{   
			count = 0;
			for(l=0;l<k;l++)
			{   
				if(num_papers[l] >= j)
					count++;
				if(count >= j)
				{   
					h_index = j;
					break;
				}   
			}   
			if(h_index != j)
				break;
		}
		printf("%d\n",h_index);
		scanf("%d",&k);
		h_index=0;
	}
	return 0;
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
