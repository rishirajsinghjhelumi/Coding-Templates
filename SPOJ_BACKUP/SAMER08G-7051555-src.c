#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		int i,j,k,c[n],p[n],correct=1,new[n];
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&c[i],&p[i]);
			new[i] = -1;
		}
		for(i=0;i<n;i++)
		{
			if(p[i] == 0)
			{
				if(new[i] == -1)
					new[i] = c[i];
				else
				{
					correct = 0;
					break;
				}
			}
			else if(p[i] > 0)
			{
				if(i+p[i] >= n)
				{
					correct = 0;
					break;
				}
				else
				{
					if(new[i+p[i]] == -1)
						new[i+p[i]] = c[i];
					else
					{
						correct = 0;
						break;
					}
				}
			}
			else if(p[i] < 0)
			{
				if(i+p[i] < 0)
				{
					correct = 0;
					break;
				}
				else
				{
					if(new[i+p[i]] == -1)
						new[i+p[i]] = c[i];
					else
					{
						correct = 0;
						break;
					}
				}
			}
		}
		if(correct == 1)
		{
			for(i=0;i<n;i++)
				printf("%d ",new[i]);
			printf("\n");
		}
		else
			printf("-1\n");
		scanf("%d",&n);
	}
	return 0;
}
