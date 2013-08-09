#include<stdio.h>
#include<math.h>
int val[10000];
int mult(int n,int len,int *a)
{
	int i,x;
	for(i=0;i<len;i++)
	{
		x = val[i] + (a[i])*n;
		a[i] = x%10;
		val[i+1] = x/10;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int len=1,n,k,i,a[5000]={0};
		scanf("%d%d",&n,&k);
		a[0] = 1;
		int m = ceil(log10(n));
		while(k--)
		{
			len += m;
			mult(n,len,a);
		}
		sub(a);
		i = len-1;
		while(!a[i--]);
		i+=2;
		while(i--)
			printf("%d",a[i]);
		printf("/%d\n",n-1);
	}
	return 0;
}
int sub(int *a)
{
	if(a[0] >= 1)
		a[0]--;
	else
	{
		int i=0;
		while(!a[i])
			a[i++] = 9;
		a[i]--;
	}
}
