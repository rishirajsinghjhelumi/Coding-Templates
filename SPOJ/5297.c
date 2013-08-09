#include<stdio.h>
int main()
{
	int n,pn=1,i,nn=0;
	while(scanf("%d",&n)!=EOF)
	{
		pn=0,nn=1,i=1;
		for(i=2;nn<n;i++)
		{
			pn = nn;
			nn = pn + i;
		}
		printf("TERM %d IS %c\n",n,((i-2)%26)+65);
	}
	return 0;
}
