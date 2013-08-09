#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,m,win=1;
		scanf("%d%d",&n,&m);
		if(n%2 && m%2)
			win = 1;
		else if(!(n%2) && !(m%2))
			win = 2;
		else if(!(n%2) && m%2)
			win = n>m?1:2;
		else if(n%2 && !(m%2))
			win = n>m?2:1;
		printf("%d\n",win);
	}
	return 0;
}
