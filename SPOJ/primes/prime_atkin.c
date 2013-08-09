#include<stdio.h>
#define limit 100000000
#define root 10001
char prime[limit+1]={0};
int main()
{
	int x,y,n,sqr;
	for(x=1;x<=root;x++)
		for(y=1;y<=root;y++)
		{
			n = 4*x*x + y*y;
			if(n<=limit && (n%12==1 || n%12==5))
				prime[n] = (prime[n]=='1')?'0':'1';
			n = 3*x*x + y*y;
			if(n<=limit && n%12==7)
				prime[n] = (prime[n]=='1')?'0':'1';
			n=3*x*x-y*y;
			if(x>y && n<=limit && n%12==11)
				prime[n] = (prime[n]=='1')?'0':'1';
		}
	for(n=5;n<=root;n++)
		if(prime[n]=='1')
		{
			sqr = n*n;
			for(x=sqr;x<=limit;x+=sqr)
				prime[x]=1;
		}
	for(n=5;n<=limit;n+=2)
		if(prime[n]=='1')
			printf("%d\n",n);
	return 0;
}
