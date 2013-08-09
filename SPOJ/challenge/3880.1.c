main()
{
	int c=0,a=0;
	char ch='*';
	while(ch!='\n')
	{
		scanf("%c",&ch);
		if(isupper(ch))
		{
			a+=3-c%4;
			c=0;
		}
		else
			c++;
	}
	printf("%d\n",a-3);
	return 0;
}
