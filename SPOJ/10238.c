#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,loc=-1,i;
		scanf("%d",&n);
		char a[n][100];
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			if(a[i][0]!='#')
				loc = i;
		}
		if(loc==-1)
		{
			for(i=loc+1;i<n-1;i++)
				printf("%s ",a[i]);
			printf("%s",a[i]);
		}
		else
		{
			for(i=loc+1;i<n;i++)
				printf("%s ",a[i]);
		}
		if(loc!=-1)
		{
			if(loc==0)
				printf("%s",a[loc]);
			else
				printf("%s ",a[loc]);
			if(loc!=0)
			{
				for(i=0;i<loc-1;i++)
					printf("%s ",a[i]);
				printf("%s",a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
