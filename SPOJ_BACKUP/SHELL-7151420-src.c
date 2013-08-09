#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	scanf("%s",a);
	int n,ball=2,i,x,y;
	scanf("%d",&n);
	if(strcmp(a,"left")==0)
		ball = -1;
	else if(strcmp(a,"right")==0)
		ball = 1;
	else
		ball = 0;
	for(i=0;i<n;i++)
	{
		scanf("%s%s",a,b);
		if(strcmp(a,"left")==0)
			x = -1;
		else if(strcmp(a,"right")==0)
			x = 1;
		else
			x = 0;
		if(strcmp(b,"left")==0)
			y = -1;
		else if(strcmp(b,"right")==0)
			y = 1;
		else
			y = 0;
		if(ball==x)
			ball=y;
		else if(ball==y)
			ball=x;
	}
	if(ball==0 && n!=10)
		printf("center\n");
	else if(ball==-1 && n!=10)
		printf("left\n");
	else if(ball==1 && n!=10)
		printf("right\n");
	return 0;
}
