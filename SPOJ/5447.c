#include<stdio.h>
int main()
{
	int n,t=1;
	scanf("%d",&n);
	while(n!=0)
	{
		if((3*n)%2==1)
		{
			printf("%d. odd ",t++);
			printf("%d\n",(n-1)/2);
		}
		else
		{
			printf("%d. even ",t++);
			printf("%d\n",n/2);
		}
		scanf("%d",&n);
	}
	return 0;
}
