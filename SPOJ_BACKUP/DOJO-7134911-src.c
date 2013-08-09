#include<stdio.h>
#include<string.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,i,x,y;
		char m[10000],j[10000];
		scanf("%d%s%d%s",&n,m,&i,j);
		int l1=strlen(m),l2=strlen(j),check;
		if( (n&1) && ((m[l1-1]-48)&1) )
		{
			x = j[l2-1]-48;
			y = i%10;
			check = (!((x+y)&1))?1:0;
		}
		else
			check = 0;
		printf("%s\n",(check)?"Possible.":"Impossible.");
	}
	return 0;
}
