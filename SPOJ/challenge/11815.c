main(t,i,j,n,m){for(scanf("%d",&t);t--&&scanf("%d%d",&n,&m);){double w=1,x,y,p=2*acos(0);n++,m++;for(i=1;i<=n/2;i++)for(j=1;j<=m/2;j++)x=2*cos(p*i/n),y=2*cos(p*j/m),w*=x*x+y*y;printf("%.0lf\n",--n%2&&--m%2?0:w);}}
