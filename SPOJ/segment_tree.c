#include<stdio.h>
#include<stdlib.h>
typedef struct segment
{
	int b,e,c,n;
}seg;
seg a[10000000];
void init(int b, int e,int n);
int main()
{
	int n,q,i;
	scanf("%d%d",&n,&q);
	a[1].b=0;
	a[1].e=n;
	init(0,n,1);
	for(i=1;i<=30;i++)
		printf("%d %d\n",a[i].b,a[i].e);
	return 0;
}
void init(int b, int e,int n)
{
	a[n].e=e;
	a[n].b=b;
	if(b<e)
	{
		init(b,(b+e)>>1,n<<1);
		init(((b+e)>>1)+1,e,(n<<1)+1);
	}
}
