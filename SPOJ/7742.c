#include<stdio.h>
int input()
{
	register int c = getchar_unlocked();
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
	int ans=0,n=input();
	while(n--)
		ans ^= input();
	printf("%d\n",ans);
	return 0;
}
