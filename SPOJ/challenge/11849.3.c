typedef long long L;
C(L l)
{
	if(!l)printf("0");
	L i=0,a=1,c=0;
	for(;l>=a;c+=l&a?1:0,i++,a<<=1);
	for(;a;i--,a>>=1)
		if(l&a)
		{
			printf("2");
			if(i!=1)printf("("),C(i),printf(")");
			if(--c)printf("+");
		}
}
int main(L n)
{
	while(scanf("%lld",&n)>0)
	printf("%lld=",n),C(n),printf("\n");
}
