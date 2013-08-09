#include<stdio.h>
typedef unsigned long long int ull;
int main()
{
	ull k,t;
	scanf("%llu",&t);
	while(t--&&scanf("%llu",&k))
	{
		ull count=0,j=0,b=1,s=k,temp=1;
		while(k>0)
		{
			if(k&temp)
			{
				count++;
				k-=temp;
			}
			temp<<=1;
			count++;
		}
		printf("%llu\n",s?count-2:0);
	}
	return 0;
}
