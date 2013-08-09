#define P(x)putchar(x)
typedef long long L;C(L l){if(!l)P('0');L i=0,a=1,c=0;for(;l>=a;c+=l&a?1:0,i++,a<<=1);for(;a;i--,a>>=1)if(l&a){P('2');if(i!=1)P('('),C(i),P(')');if(--c)P('+');}}int main(L n){while(scanf("%llu",&n)>0)printf("%llu=",n),C(n),P('\n');}
