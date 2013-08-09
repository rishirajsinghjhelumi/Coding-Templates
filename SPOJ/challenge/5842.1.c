#include<stdio.h>
int main()
{int t,a,x,y;scanf("%d%*c",&t);while(t--){c=getchar();while(c!='\n'){a=c-65;if(a==9)x=2,y=4;else if(a<26&&a>=0){x=a<9?a/5+1:(a-1)/5+1;y=a<9?a%5+1:(a-1)%5+1;}else{c=getchar();continue;}printf("%d%d ",x,y);c=getchar();}printf("\n");}}
