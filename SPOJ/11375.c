#include<stdio.h>
int main()
{
	int test_cases,t;
	scanf("%d",&test_cases);
	for(t=1;t<=test_cases;t++)
	{
		int m,r1,r2,spy = 0;
		int a[100000]={0},b[100000]={0};
		scanf("%*d%d",&m);
		while(m--)
		{
			scanf("%d%d",&r1,&r2);
			if(b[r1] == 1)
				spy=1;
			else
				a[r1]=1;
			if(a[r2] == 1)
				spy=1;
			else
				b[r2]=1;
		}
		printf("Scenario #%d: %s\n",t,(spy==0)?"spying":"spied");
	}
	return 0;
}
