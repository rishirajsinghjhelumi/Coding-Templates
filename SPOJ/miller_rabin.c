#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define iterations 10
typedef unsigned long long int ull;
int primes[100],num_primes=0;
ull mulmod( ull a,ull b,ull c)
{
	ull x = 0,y=a%c;
	while(b > 0)
	{
		if(b&1)
			x = (x+y)%c;
		y = (y<<1)%c;
		b >>=1;
	}
	return x%c;
}
ull power(ull n ,ull k,ull mod)
{
	ull temp = 1,ans=1;
	while(k>0)
	{
		if(k&temp)
		{
			ans = mulmod(ans,n,mod);
			k-=temp;
		}
		temp <<=1;
		n = mulmod(n,n,mod);
	}
	return ans%mod;
}
void prime_sieve()
{
	int i,j,max=100,root=11;
	int p[101]={0};
	for(i=2;i<root;i++)
		if(!p[i])
			for(j=i+i;j<max;j+=i)
				p[j]=1;
	primes[num_primes++] = 2;
	for(i=3;i<max;i+=2)
		if(!p[i])
			primes[num_primes++] = i;
}
int main()
{
	ull n,i,check;
	scanf("%llu",&n);
	check = miller_rabin(n);
	printf("%s\n",check?"PRIME":"COMPOSITE");
	return 0;
}
int miller_rabin(ull n)
{
	if(n==2)
		return 1;
	if( (n%2==0 && n!=2) || (n%3==0 && n!=3) || (n%5==0 && n!=5) )
		return 0;
	ull d=n-1,s=0,x,i,a;
	while(!(d%2))
	{
		d>>=1;
		s++;
	}
	for(i=0;i<iterations;i++)
	{
		a=rand()%(n-2)+2;
		if(is_composite(a,d,n,s))
			return 0;
	}
	return 1;
}
int is_composite(ull a,ull d, ull n,ull s)
{
	int i;
	if(power(a,d,n)==1)
		return 0;
	for(i=0;i<s;i++)
		if(power(a,(1<<i)*d,n)==n-1)
			return 0;
	return 1;
}
