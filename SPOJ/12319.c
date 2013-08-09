#include<stdio.h>
#define gc getchar_unlocked
int main()
{
	int t;
	scanf("%d",&t);
	gc();
	while(t--)
	{
		int num1=0,num2=0;
		char ch=gc();
		while(ch!='\n')
		{
			num1 = ((num1<<3) + (num1<<1) + ch - '0')%252;
			num2 = ((num2<<3) + (num2<<1) + ch - '0')%525;
			ch = gc();
		}
		printf("%s %s\n",!num1?"Yes":"No",!num2?"Yes":"No");
	}
	return 0;
}
