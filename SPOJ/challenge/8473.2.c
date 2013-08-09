f(n){return n<2?2:f(n-1)*(4*n-2)/n;}main(i,n){;scanf("%d",&i);while(i--&&scanf("%d",&n))printf("%d\n",f(n));}
