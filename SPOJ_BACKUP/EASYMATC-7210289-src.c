#include<stdio.h>
typedef long long int L;
L g(L a,L b)
{
	if(!b)
		return a;
	return g(b,a%b);
}
int main()
{
	L t,n,m,a,d,i,x[5],j;
	scanf("%lld",&t);
	while(t--&&scanf("%lld%lld%lld%lld",&n,&m,&a,&d))
	{
		L p=0,q=0;
		for(i=0;i<5;i++)
			x[i]=a+i*d;
		n--;
		for(i=1;i<32;i++)
		{
			L b=1,c=0,s,l=1;
			for(j=0;j<5;j++,b<<=1)
				if(i&b)
					c++,l=l*x[j]/g(x[j],l);
			s=c&1?1:-1;
			p+=s*(n/l);
			q+=s*(m/l);
		}
		printf("%lld\n",m-n-q+p);
	}
	return 0;
}
