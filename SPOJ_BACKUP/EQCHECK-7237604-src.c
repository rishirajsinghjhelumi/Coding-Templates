g(a,b){return !b?a:g(b,a%b);}main(t,a,b,c){scanf("%d",&t);while(t--&&scanf("%d%*c%*c%d%*c%*c%d",&a,&b,&c))printf("%s\n",!(c%g(a,b))?"yes":"no");}
