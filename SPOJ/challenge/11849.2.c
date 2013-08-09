typedef long long int ull;
void convert(ull l)
{
	if(!l)
		printf("0");
	ull i,a=1,c=0;
	for(i=0;l>=a;i++,a<<=1)
		if(l&a)
			c++;
	for(;a;i--,a>>=1)
		if(l&a)
		{
			printf("2");
			if(i!=1)
			{
				printf("(");
				convert(i);
				printf(")");
			}
			if(--c)
				printf("+");
		}
}
int main()
{
	ull n;
	while(scanf("%lld",&n)>0)
	printf("%lld=",n),convert(n),printf("\n");
}
