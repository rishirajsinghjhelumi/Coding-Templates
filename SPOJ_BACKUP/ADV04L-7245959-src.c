#include<stdio.h>
typedef unsigned long long int ull;
ull fib[100];
ull ind[100],term=0,done=0;
ull get_fib(ull n,ull start);
void generate_fibonacci()
{
	ull i,j;
	fib[1] = 1;
	fib[2] = 1;
	for(i=3;i<=75;i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
		//printf("%llu\n",fib[i]);
	}
}
int main()
{
	generate_fibonacci();
	ull t;
	scanf("%llu",&t);
	while(t--)
	{
		ull n,i,count=0;
		term=done=0;
		scanf("%llu",&n);
		for(i=1;i<=75;i++)
			if(fib[i]>n)
				break;
		get_fib(n,i-1);
		for(i=0;i<term;i++)
			count+= fib[ind[i]+1];
		printf("%llu\n",count);
	}
	return 0;
}
ull get_fib(ull n,ull start)
{
	ull i;
	for(i=start;i>=1;i--)
	{
		if(done)
			return;
		if(fib[i]==n)
		{
			done = 1;
			ind[term++] = i;
			return;
		}
		else if(fib[i]<n)
		{
			ind[term++] = i;
			get_fib(n-fib[i],i-1);
		}
	}
}
