#include<stdio.h>
#define max 1000000
int d[max+10],a[max+10];
int main()
{
	int i,j,k=0,m,n;
	for(i=1;i<=max;i++)
		for(j=i;j<=max;j+=i)
			d[j]++;
	for(m=1;m<=max;m++)
	{
		if(d[m]<4)
			a[m]=1;
		if(!a[m])
			if(++k%108==0)
				printf("%d\n",m);
		for(n=m+m;n<=max;n+=m)
			if(d[n]%d[m])
				a[n] = 1;
	}
	return 0;
}
