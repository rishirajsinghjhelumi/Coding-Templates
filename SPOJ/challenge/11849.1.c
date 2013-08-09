#include<stdio.h>
typedef unsigned long long int ull;
void convert(ull l)
{
	if(!l)
		printf("0");
	ull i,a=1;
	//for(i=0;l>a;i++,a<<=1);
	//printf("a==%lld\n",a);
	for(i=0;l;i++,l>>=1)
	{
		if(l&1)
		{
			printf("2");
			if(i!=1)
			{
				printf("(");
				convert(i);
				printf(")");
			}
			if(l>>1)
				printf("+");
		}
	}

}
int main()
{
	ull t,n;
	for(scanf("%lld",&t);t--;scanf("%lld",&n),convert(n),printf("\n"));
	return 0;
}
