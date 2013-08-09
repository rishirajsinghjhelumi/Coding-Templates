#include<math.h>
long long n,m,i,j,s;main(t){for(scanf("%d",&t);t--&&scanf("%lld%lld",&n,&m);){double w=1,x,y;for(i=1;i<=ceil(n/2);i++)for(j=1;j<=ceil(m/2);j++)x=2*cos(M_PI*i/(n+1)),y=2*cos(M_PI*j/(m+1)),w*=x*x+y*y;s=w;printf("%lld\n",n%2&&m%2?0:s);}}
