#define m 6<<18
i=1,p[m],j,k=1,n[m],a;main(){while(i++<m)if(!p[i]){n[k++]=i;for(j=2*i;j<m;j+=i)p[j]=1;}while(scanf("%d",&a)>0)printf("%d\n",n[a]);return 0;}
