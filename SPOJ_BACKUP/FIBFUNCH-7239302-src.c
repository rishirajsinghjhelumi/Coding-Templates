typedef long long int L;
L m;
L f(L n)
{
	L a=1,b=0,p=0,q=1,s,r;
	while(n) 
	{
		if(!(n%2))
		{
			r=p;
			p=(p*p+q*q)%m;
			q=(2*r*q+q*q)%m;
			n/=2;
		}
		else 
		{
			s=a;
			a=(b*q+a*q+a*p)%m;
			b=(b*p+s*q)%m;
			n--;
		}
	}
	return b;
}
main()
{
	L t,a,b,n;
	for(scanf("%lld",&t);t--&&scanf("%lld%lld%lld%lld",&a,&b,&n,&m);printf("%lld\n",(a*f(n)+b*f(n+1)-b+n*m)%m));
}
