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
	for(i=3;i<=70;i++)
		fib[i] = fib[i-1] + fib[i-2];
}
int main()
{
	generate_fibonacci();
	ull n,i;
	scanf("%llu",&n);
	for(i=1;i<=70;i++)
		if(fib[i]>n)
			break;
	get_fib(n,i-1);
	for(i=0;i<term;i++)
		printf("%llu\n",fib[ind[i]]);
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
