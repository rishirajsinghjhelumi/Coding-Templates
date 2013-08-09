#include<stdio.h>
#include<iostream>
#include<algorithm>
int main()
{
	int n;
	scanf("%d",&n);
	while(n!=-1)
	{
		int i,j,k,x[n+2],y[n+2],res[n+2];
		long double sum1=0,sum2=0,ans;
		for(i=0;i<n;i++)
			scanf("%d",&x[i]);
		x[n] =  x[0];
		x[n+1] = x[n-1];
		for(i=0;i<n;i++)
			scanf("%d",&y[i]);
		std::sort(y,y+n);
		int nn=n+2;
		std::sort(x,x+nn);
		for(i=0;i<nn;i++)
			res[i]  = x[(nn+i-1)%nn] - x[(i+1)%nn];
		std::sort(res+1,res+nn-1);
		for(i=0;i<n;i++)
			sum1 += y[i]*res[i+1];
		for(i=n-1;i>=0;i--)
			sum2 += y[n-i-1]*res[i+1];
		ans = abs(sum1)>abs(sum2)?abs(sum1):abs(sum2);
		printf("%.1Lf\n",ans/2);
		scanf("%d",&n);
	}
	return 0;
}
