long long int x,s[2];
main(t,n,i)
{
	for(scanf("%d",&t);t--&&scanf("%d",&n);)
	{
		for(s[1]=s[0]=i=0;n--&&scanf("%lld",&x);s[i%2]+=i++%2?x>0?x:0:x<0?-x:0);
		printf("%s\n",s[1]<s[0]?"Every Girl Lies!":"Some Mirrors Lie!");
	}
}
