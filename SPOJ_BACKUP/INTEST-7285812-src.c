#include<stdio.h>
int input()
{
	char c = getchar_unlocked();
	int x=0;
	while(c>=48 && c<=57)
	{
		x = (x<<3)+(x<<1)+c-48;
		c = getchar_unlocked();
	}
	return x;
}
int main()
{
	int n,k,count=0;
	n = input();
	k = input();
	while(n--)
	{
		if(!(input()%k))
			count++;
	}
	printf("%d\n",count);
	return 0;
}
