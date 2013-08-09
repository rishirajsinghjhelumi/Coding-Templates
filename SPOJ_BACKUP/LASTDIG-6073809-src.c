#include<stdio.h>
void p(int n){printf("%d\n",n);}
int main(){int i,t,a,c,d;scanf("%d",&t);while(t){long int b;scanf("%d%ld",&a,&b);c=a%10;if(b==0||c==1)p(1);else if(c==0)p(0);else if(c==2){d=b%4;if(d==0)p(6);if(d==1)p(2);if(d==2)p(4);if(d==3)p(8);}else if(c==3){d=b%4;if(d==0)p(1);if(d==1)p(3);if(d==2)p(9);if(d==3)p(7);}else if(c==4){d=b%2;if(d==0)p(6);else p(4);}else if(c==5||c==6)p(c);else if(c==7){d=b%4;if(d==0)p(1);if(d==1)p(7);if(d==2)p(9);if(d==3)p(3);}else if(c==8){d=b%4;if(d==1)p(8);if(d==2)p(4);if(d==3)p(2);if(d==0)p(6);}else if(c==9){d=b%2;if(d==1)p(9);else p(1);}t--;}return 0;}
