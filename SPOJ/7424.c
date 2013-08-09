#include<stdio.h>
#include<math.h>
int main()
{
	int g,b;
	scanf("%d%d",&g,&b);
	while(g!=-1 && b!=-1)
	{
		double a,c;
		if(g==0 && b==0)
			printf("0\n");
		else if(g==b)
			printf("1\n");
		else if(g==0)
			printf("%d\n",b);
		else if(b==0)
			printf("%d\n",g);
		else
		{
			if(g>b)
			{
				printf("%d\n",(g+b)/(b+1));
			}
			else
			{
				printf("%d\n",(g+b)/(g+1));
			}
		}
		scanf("%d%d",&g,&b);
	}
	return 0;
}
