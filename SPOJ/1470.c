#include<stdio.h>
#include<string.h>
void print(int a[] ,int n);
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
		for(j=0;j<m;j++)
		{
		//	print(a,n);
			scanf("%s",str);
			if(strcmp(str,"GET-SUM")==0)
			{
				scanf("%d%d",&x,&y);
				int i;
				long long int sum=0;
				for(i=x-1;i<x+y-1;i++)
					sum += a[i];
				printf("%lld\n",sum);
			}
			else if(strcmp(str,"MAX-SUM")==0)
			{
				int i,l,k;
			/*	long long int max_so_far = -999999, max_ending_here = 0;
				for(i=0;i<n;i++)
				{
					max_ending_here = max_ending_here + a[i];
					if(max_ending_here < 0)
						max_ending_here = 0;
					if(max_so_far < max_ending_here)
						max_so_far = max_ending_here;
						}
						printf("%lld\n",max_so_far);*/
				long long int max_sum = -99999,max_here = 0;
				int flag = 0;
				for(i=0;i<n;i++)
				{
					max_here += a[i];
					if(max_here < 0)
					{
						max_here = 0;
						if(!flag)
						{
							if(max_sum < a[i])
								max_sum = a[i];
						}
					}
					else if(max_sum < max_here) {
						max_sum = max_here;
						flag = 1;
					}
				}
				printf("%lld\n",max_sum);
			}
			else if(strcmp(str,"REVERSE")==0)
			{
				scanf("%d%d",&x,&y);
				int i,temp;
				for(i=0;i<y/2;i++)
				{
					temp = a[x+i-1];
					a[x+i-1] = a[x+y-i-2];
					a[x+y-i-2] = temp;
				}
			}
			else if(strcmp(str,"DELETE")==0)
			{
				scanf("%d%d",&x,&y);
				if(y>n-x)
					y=n-x+1;
				int i;
				for(i=x-1;i<n-y;i++)
					a[i] = a[i+y];
				n=n-y;
			}
			else if(strcmp(str,"INSERT")==0)
			{
				scanf("%d%d",&x,&y);
				int b[y],l;
				for(l=0;l<y;l++)
					scanf("%d",&b[l]);
				int i;
				for(i=n-1;i>=x;i--)
					a[i+y] = a[i];
				for(i=x;i<x+y;i++)
					a[i] = b[i-x];
				n=n+y;
			}
			else if(strcmp(str,"MAKE-SAME")==0)
			{
				scanf("%d%d%d",&x,&y,&z);
				int i;
				for(i=x-1;i<x+y-1;i++)
					a[i] = z;
			}
		}
	}
	return 0;
}
void print(int a[] ,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
