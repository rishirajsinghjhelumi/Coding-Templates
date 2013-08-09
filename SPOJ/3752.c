#include<stdio.h>
#include<string.h>
int a1[6000],a2[6000],a3[6000],a4[6000];
int main()
{
	char s[2000],ch;
	int i=0,j,len,num,count = 0,d=0;
	while(scanf("%c",&ch) && ch!='=')
	{
		if(ch==0)
		s[i++] = ch;
	}
	scanf("%d",&num);
	s[i] = '\0';
	len = i;
	return 0;
}
