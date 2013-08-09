#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		int a[n],i,j=0,k=0,start[n],end[n],people[n],max=0,maxs=0,maxe=0,end_index=0,index=0,start_index=0;
		long long int time = 0;
		scanf("%d",&a[0]);
		start[j] = a[0];
		for(i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i] - a[i-1] != 1)
			{				
				people[j] = a[i-1] - start[j] + 1;
				if(people[j] > max)
				{
					end_index = i - 1;
					start_index = index;
				}
				end[j++] = a[i-1];
				start[j] = a[i];
				index = i;
			}
		}
		people[j] = a[i-1] - start[j] + 1;
		if(people[j] > max)
		{
			end_index = i - 1;
			start_index = index;
		}
		end[j++] = a[i-1];
		printf("%lld\n",time);
		scanf("%d",&n);
	}
	return 0;
}
