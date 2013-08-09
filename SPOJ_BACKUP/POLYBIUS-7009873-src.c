#include<stdio.h>
main(){int t,a,x,y;scanf("%d%*c",&t);while(t--){char c=getchar();while(c!='\n'){a=c-65;if(a<0){c=getchar();continue;}if(a==9)x=2,y=4;else{x=a<9?a/5+1:(a-1)/5+1;y=a<9?a%5+1:(a-1)%5+1;}c=getchar();printf("%d%s",10*x+y,c!='\n'?" ":"");}printf("\n");}return 0;}
