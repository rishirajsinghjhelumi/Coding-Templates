#include<stdio.h>
int f(unsigned long long int a);
int main()
{
	int test_cases,i;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		unsigned long long int n,m,k,knife,hand,x=1;
		scanf("%llu%llu%llu",&n,&m,&k);
		hand = n*m*k-1;
		knife=f(n)+f(k)+f(m);
		printf("Case #%d: %llu %llu\n",i+1,hand,knife);
	}
	return 0;
}
int f(unsigned long long int a)
{
	int i=0;
	for(--a;a;a>>=1)
		++i;
	return i;
}
