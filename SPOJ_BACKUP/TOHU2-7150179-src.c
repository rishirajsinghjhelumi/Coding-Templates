#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		char a[200],ch;
		int i,j,k,check=1,b[200];
		for(i=1;i<=99;i++)
		{
			scanf("%d%*c",&b[i]);
			scanf("%c",&a[b[i]]);
		}
		ch = a[9];
		for(i=9;i<=81;i+=9)
		{
			if(a[i]!=ch)
			{
				check = 0;
				break;
			}
		}
		printf("%s\n",(check)?"YES":"NO");
	}
	return 0;
}
