#include<stdio.h>
#include<algorithm>
#include<map>
#define MAX 100010
using namespace std;
int a[MAX];
int ans[MAX];
int values[80][MAX]={0};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,s;
		scanf("%d%d%d",&n,&m,&s);
		int i,j;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int arr[800]={0};
		int count[800]={0};
		int div = n/s;
		int rem = n%s;
		int k =0;
		int n1 = n/s;
		int n2 = n/s + 1;
		for(i=0;i<n;i++)
		{
			int mod = a[i] % m;
			int check = 0;
			for(j=0;j<k;j++)
				if(arr[j] == mod)
				{
					values[j][count[j]++] = a[i];
					check = 1;
					break;
				}
			if(!check)
			{
				arr[k] = mod;
				values[k][count[k]++] = a[i];
				k++;
			}
		}
		int check = 1;
		int ab[1000][2];
		for(i=0;i<k;i++)
		{
			if(rem==0)
			{
				if(count[i]>=div && count[i]%n1 == 0)
				{
					ab[i][0] = count[i]/n1;
					ab[i][1] = 0;
					continue;
				}
				else
				{
					check = 0;
					break;
				}
			}
			else
			{
				if(count[i]>=div)
				{
					if((count[i]%n1 == 0 || count[i]%n2 == 0) )
					{
						if(count[i]%n1 == 0)
						{
							ab[i][0] = count[i]/n1;
							ab[i][1] = 0;
						}
						else
						{
							ab[i][0] = 0;
							ab[i][1] = count[i]/n2;
						}
						continue;
					}
					else
					{
						int x,y,c = 0;
						for(x=0;x<=s;x++)
						{
							for(y=0;y<=s;y++)
								if((x+y)*div + y == count[i])
								{
									c = 1;
									ab[i][0] = x;
									ab[i][1] = y;
									break;
								}
							if(c)
								break;
						}
						if(c)
							continue;
						else
						{
							check = 0;
							break;
						}
					}
				}
				else
				{
					check = 0;
					break;
				}
			}
		}
		if(!check)
		{
			printf("-1\n");
			continue;
		}
		if(rem==0)
		{
			int l = 0,start = 0;
			for(i=0;i<k;i++)
			{
				int x = ab[i][0];
				int z = 0;
				for(l=0;l<x;l++)
				{
					for(j=0;j<n1;j++)
						ans[start+j*s] = values[i][z++];
					start++;
				}
			}
		}
		else
		{
			int l = 0,start = 0,start2 = s-1;
			for(i=0;i<k;i++)
			{
				int x = ab[i][0];
				int y = ab[i][1];
				int z = 0;
				for(l=0;l<y;l++)
				{
					for(j=0;j<n2;j++)
						ans[start+j*s] = values[i][z++];
					start++;
				}
				for(l=0;l<x;l++)
				{
					for(j=0;j<n1;j++)
						ans[start2+j*s] = values[i][z++];
					start2--;
				}
			}
		}
		check = 1;
		int sum = 0;
		for(i=0;i<s;i++)
			sum+=ans[i];
		for(i=0;i<n-s+1;i++)
		{
			if(sum%m!=0)
			{
				check = 0;
				break;
			}
			sum = sum - ans[i] + ans[i+s];
		}
		if(!check)
		{
			printf("-1\n");
			continue;
		}
		for(i=0;i<n-1;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[i]);
	}
	return 0;
}
