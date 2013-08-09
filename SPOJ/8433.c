#include<math.h>
#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)>0)
	{
		int i,a=sqrt(n/2)+1,c,b,count=0;
		for(i=0;i<a;i++)
		{
			b=n-i*i;
			c=sqrt(b);
			if(c*c==b)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
