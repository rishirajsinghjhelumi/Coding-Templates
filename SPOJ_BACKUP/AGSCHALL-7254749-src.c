typedef long long int L;
L p,q,M,t,r,d,n,T[6];
L f(L n)
{
	L m[2][2]={{1+r,-r},{1,0}},a[2][2]={{1,0},{0,1}};
	while(n)
	{
		L x=m[0][0],y=m[0][1],z=m[1][0],w=m[1][1];
		if(n&1)
		{
			L i=a[0][0],j=a[0][1],k=a[1][0],l=a[1][1];
			a[0][0]=(x*i+y*k)%M;
			a[0][1]=(x*j+y*l)%M;
			a[1][0]=(z*i+w*k)%M;
			a[1][1]=(z*j+w*l)%M;
		}
		n>>=1;
		m[0][0]=(x*x+y*z)%M;
		m[0][1]=(x*y+y*w)%M;
		m[1][0]=(x*z+z*w)%M;
		m[1][1]=(z*y+w*w)%M;
	}
	return(a[0][0]*p+a[0][1]*q)%M;
}
main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld",&q,&d,&r,&n,&M);
		T[1]=q;
		T[2]=(q+d)%M;
		T[3]=p=(T[2]*r)%M;
		T[4]=(p+d)%M;
		printf("%lld\n",n<5?T[n]:n&1?(f((n+1)/2-2)+n*M)%M:(f(n/2-2)+d+n*M)%M);
	}
}
