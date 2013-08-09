#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d",&a,&b);
	while(a!=-1 && b!=-1)
	{
		f=b%37;
		e=a%1000;
		d=b/37;
		c=a/1000;
		printf("%s\n",(f==0 && e==0 && c==d)?"Y":"N");
		scanf("%d%d",&a,&b);
	}
	return 0;
}
