#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define MAXN  100000000  
#define P1    1562501    
#define P2    50000000   
#define P3    5000       
int  sieve[P2];
#define GET(b) ((sieve[(b)>>5]>>((b)&31))&1)
void make()
{
	int i, j, k;
	memset(sieve, 0, sizeof(sieve));
	for (k = 1; k <= P3; k++)
		if (!GET(k))
			for(j=2*k+1,i=2*k*(k+1);i<P2;i+=j) 
				sieve[i>>5]|=1<<(i&31);
}

int isprime(int p) 
{ 
	return p==2 || (p>2 && (p&1)==1 && (GET((p-1)>>1)==0)); 
} 
int main()
{
	int i, n=0;
	make();
	for (i = 0; i <= MAXN; i++)
		if (isprime(i))
			sieve[++n] = i;
	scanf("%d",&i);
	while(i--)
	{
		scanf("%d",&n);
		printf("%d\n",sieve[n]);
	}
	return 0;
}
