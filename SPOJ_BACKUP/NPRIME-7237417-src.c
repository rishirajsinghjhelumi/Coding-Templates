#define m 6<<18
i=1,j,k=1,n[m],p[m];main(){for(;i++<m;)if(!p[i])for(n[k++]=i,j=i*2;j<m;j+=i)p[j]=1;for(;scanf("%d",&i)>0;printf("%d\n",n[i]));return 0;}
