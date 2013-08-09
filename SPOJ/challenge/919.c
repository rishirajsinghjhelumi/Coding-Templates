#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define iterations 1
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
			ans = (ans*n)%mod;
			k-=temp;
		}
		temp <<=1;
		n = (n*n)%mod;
	}
	return ans%mod;
}
int miller_rabin(ull n)
{
	if(n==1)
		return 0;
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
	a=rand()%(n-2)+2;
	if(is_composite(a,d,n,s))
		return 0;
	a=rand()%(n-2)+2;
	if(is_composite(a,d,n,s))
		return 0;
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
int main()
{
	ull n,i=0,check,test_cases;
	ull x=1,a=1234567890,modulas = 2147483648;
	while(1)
	{
		printf("%llu\n",x);
		x=(x+a)%modulas;
	}
	return 0;
}
