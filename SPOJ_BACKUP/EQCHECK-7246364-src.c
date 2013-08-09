g(a,b){return!b?a:g(b,a%b);}main(t,a,b,c){for(scanf("%d",&t);t--;scanf("%dx+%dy=%d",&a,&b,&c),printf("%s\n",c%g(a,b)?"no":"yes"));}
