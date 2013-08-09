#include<stdio.h>
#define m 1400000 
int i,p[m]={0},j,n[m],k=0,a;int main(){for(i=2;i<m;i++)if(!p[i]){n[k++]=i;for(j=2*i;j<m;j=j+i)p[j]=1;}while(scanf("%d",&a)!=EOF)printf("%d\n",n[a-1]);return 0;}
