#include<stdio.h>
int input()
{
	register char c = getchar_unlocked();
	int x=0;
	while(c<48 || c>57)
		c=getchar_unlocked();
	while(c>=48 && c<=57)
	{
		x = (x<<3)+(x<<1)+c-48;
		c = getchar_unlocked();
	}
	return x;
}
int main()
{
	int n = input(),count=0,best=0,x;
	while(n--)
	{
		x = input();
		if(!count)
			best = x,count=1;
		else
			count += best==x?1:-1;
	}
	printf("%d\n",best);
	return 0;
}
