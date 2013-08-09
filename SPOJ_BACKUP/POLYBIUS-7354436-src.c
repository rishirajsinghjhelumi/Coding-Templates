main(t,a){for(scanf("%d%*c",&t);t--;){char c=getchar();while(c!=10){a=c-65,c=getchar();if(a<0)continue;printf("%d%c",10*(a==9?2:a<9?a/5+1:(a-1)/5+1)+(a==9?4:a<9?a%5+1:(a-1)%5+1),c!=10?32:10);}}}
