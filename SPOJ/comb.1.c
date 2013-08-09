#include<stdio.h>
typedef long long int ull;
ull minv(ull a, ull n) 
{
	ull i = n, v = 0, d = 1;
	while (a>0) 
	{
		ull t = i/a, x = a;
		a = i % x;
		i = x;
		x = d;
		d = v - t*x;
		v = x;
	}
	return (v+n)%n;
}
int main()
{
	ull i,mod = 1000000007,mod2=mod-1,mm=mod2>>1,mod4=148721;
	ull fact[200010];
	ull ncr[100010];
	ncr[0] = 1;
	printf("%d\n",1);
	mm--;
	fact[0] = 1;
	for(i=1;i<=200000;i++)
		fact[i] = (fact[i-1]*i)%mm;
	for(i=42;i<=100000;i++)
	{
		ncr[i] = (fact[2*i]*((minv(fact[i],mm)*minv(fact[i],mm))%mm))%mm;
		printf("%lld\n",ncr[i]);
	}
	return 0;
}
