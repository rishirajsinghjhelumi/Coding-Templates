#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n,k,i,c;
	while(scanf("%d",&n) && n)
	{
		k=0;
		n=2*n;
		c=1;
		while(n%3==0)
		{
			n/=3;
			k++;
		}
		c*=(k+1);
		int r = sqrt(n),f;
		for(i=1;1;i++)
		{
			f=6*i-1;
			if(f>r)break;
			k=0;
			while(n%f==0){n/=f;k++;}
			c*=(k+1);
			f=6*i+1;
			if(f>r)break;
			k=0;
			while(n%f==0){n/=f;k++;}
			c*=(k+1);
		}
		printf("%d\n",2*c);
	}
	return 0;
}
