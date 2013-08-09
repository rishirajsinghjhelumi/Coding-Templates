main()
{
	int n,a[14]={2},i=0;
	while(i++<14)
		a[i]=(4*i+2)*a[i-1]/(i+1);
	scanf("%d\n",&i);
	while(i--)
	{
		scanf("%d",&n);
		printf("%d\n",a[--n]);
	}
}
