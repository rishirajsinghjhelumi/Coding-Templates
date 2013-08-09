#include<stdio.h>
#include<math.h>
typedef unsigned long long int ull;
int main()
{
	ull start[51],end[51],i,x=2;
	start[0] = 1;
	end[0] = 2;
	for(i=1;i<=50;i++)
	{
		start[i] = start[i-1] + x;
		x<<=1;
		end[i] = end[i-1] + x;
	}
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ull n,bits;
		scanf("%llu",&n);
		for(i=0;i<=50;i++)
			if(start[i]<=n && n<= end[i])
			{
				bits = i+1;
				break;
			}
		n-=start[i];
		int number[100]={0};
		i=0;
		while(n)
		{
			number[bits-(++i)] = n%2;
			n>>=1;
		}
		for(i=0;i<bits;i++)
			printf("%d",(number[i]==0)?5:6);
		printf("\n");
	}
	return 0;
}
