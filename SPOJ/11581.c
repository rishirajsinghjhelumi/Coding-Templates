#include<stdio.h>
#include<string.h>
int main()
{
	int t,test_cases;
	char ch[100000];
	t=0;
	while(scanf("%s",ch)!=EOF)
	{
		int l = strlen(ch);
		int i,x[100000],dec = 0;
		for(i=0;i<l;i++)
		{
			if(ch[i] == 'I')
				x[i] = 1;
			else if(ch[i] == 'V')
				x[i] = 5;
			else if(ch[i] == 'X')
				x[i] = 10;
			else if(ch[i] == 'L')
				x[i] = 50;
			else if(ch[i] == 'C')
				x[i] = 100;
			else if(ch[i] == 'D')
				x[i] = 500;
			else if(ch[i] == 'M')
				x[i] = 1000;
		}
		for(i=0;i<l-1;i++)
		{
			if( x[i] < x[i+1] )
				dec = dec - x[i];
			else
				dec = dec + x[i];
		}
		printf("Case %d: %d\n",++t,dec + x[l-1]);
	}
	return 0;
}
