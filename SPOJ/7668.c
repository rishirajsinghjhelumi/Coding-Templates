#include<stdio.h>
#include<string.h>
int main()
{
	char s[100000];
	int t=1;
	while(scanf("%s",s)>0)
	{
		int i,count = 0,len=strlen(s);
		char flip = '1';
		for(i=0;i<len;i++)
			if(s[i] == flip)
			{
				count++;
				flip = (flip=='0')?'1':'0';
			}
		printf("Game #%d: %d\n",t++,count);
	}
	return 0;
}
