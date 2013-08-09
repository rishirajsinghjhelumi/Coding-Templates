#define S(x)scanf("%d",&x)
x,y,p,q,r,s,c,t;C(a,b,l){if(a==x&&b==y)c++;else if(a<=x&&b<=y&&(a!=p||b!=q)&&(a!=r||b!=s))C(a+1,b,l+1),C(a,b+1,l+1);}main(){for(S(t);t--;S(x),S(y),S(p),S(q),S(r),S(s),c=0,C(0,0,0),printf("%d\n",c));return 0;}
