main()
{
	unsigned long long int t,n,y;
	scanf("%llu",&t);
	while(t--&&scanf("%llu",&n))
		y=n*(n+2)*((n<<1)+1),printf("%llu\n",n&1?(y-1)>>3:y>>3);
}
