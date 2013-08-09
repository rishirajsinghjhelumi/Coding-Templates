#include<stdio.h>
int main()
{
	unsigned long long int n,x,y,sum=0,i;
	scanf("%llu",&n);
	if(n!=1)
	{
		scanf("%llu%llu",&x,&y);
		sum += (x>y)?x:y;
		x=y;
		for(i=2;i<n;i++)
		{
			scanf("%llu",&y);
			sum += (x>y)?x:y;
			x=y;
		}
	}
	printf("%llu\n",sum);
	return 0;
}
