#include<stdio.h>
#include<math.h>
#define max 10000000
#define m (max-1)>>1
#define x (floor(sqrt(max)-1))/2
int i,j,k=1;
char p[m];
int primes[max+10];
void gen_prime();
int input();
int main()
{
	gen_prime();
	int t=input(),n,a,b,i1,i2;
	while(t--)
	{
		n = input();
		a = (n>>1) + 1;
		if(a%2==0 && a!=2)
			a++;
		while(1)
		{
			if(primes[a])
			{
				i1 = primes[a];
				break;
			}
			a+=2;
		}
		if(n%2==0 && n!=2)
			n--;
		while(1)
		{
			if(primes[n])
			{
				i2 = primes[n];
				break;
			}
			n-=2;
		}
		printf("%d\n",i2-i1+1);
	}
	return 0;
}
void gen_prime()
{
	for(i=1;i<=x;i++)
		if(!p[i])
			for(j=((i+1)*i)<<1;j<=m;j+=(i<<1)+1)
				p[j]='1';
	primes[2] = k++;
	for(i=1;i<=m;i++)
		if(!p[i])
			primes[(i<<1)+1] = k++;
}
int input()
{
	register int c = getchar_unlocked();
	int y=0;
	while(c>=48 && c<=57)
	{
		y = (y<<3)+(y<<1)+c-48;
		c = getchar_unlocked();
	}
	return y;
}
