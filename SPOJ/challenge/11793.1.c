x,y,p,q,r,s,t;
C(a,b,l)
{
	if(a>x||b>y||(a==p&&b==q)||(a==r&&b==s))
		return 0;
	if(a==x&&b==y)
		return 1;
	return C(a+1,b,l+1)+C(a,b+1,l+1);
}
main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d",&x,&y,&p,&q,&r,&s);
		printf("%d\n",C(0,0,0));
	}
	return 0;
}
