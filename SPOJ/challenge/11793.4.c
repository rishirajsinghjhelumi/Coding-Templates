S(x){scanf("%d",&x);}
x,y,p,q,r,s,c;C(a,b,l){if(a>x||b>y||a==p&&b==q||a==r&&b==s);else if(a==x&&b==y)c++;else C(a+1,b,l+1),C(a,b+1,l+1);}main(t){for(S(t);t--;S(x),S(y),S(p),S(q),S(r),S(s),c=0,C(0,0,0),printf("%d\n",c));return 0;}
