int n;main(i,m)char**m;{while(--i)n^=atoi(m[i]);
	while(*++m)if((n^atoi(*m))<atoi(*m)||atoi(*m)*!n
		     ){printf("%d\n",(n^atoi(*m))-!n);while(*++m)puts
		(*m);m--;}else puts(*m);} /* play: nim <nums> */
