#include<stdio.h>
int g(int a,int b){if(b==0)return a;return g(b,a%b);}int main(){int t,a,b,c;scanf("%d",&t);while(t--){scanf("%d%*c%*c%d%*c%*c%d",&a,&b,&c);printf("%s\n",(c%g(a,b)==0)?"yes":"no");}return 0;}
