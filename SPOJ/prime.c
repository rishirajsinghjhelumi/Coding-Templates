#include<stdio.h>
#define max 10000000
#include<math.h>
#define root sqrt(max)+1
int i,j,k=1;
int p[max];
int ind[max];
int main()
{
	for(i=2;i<root;i++)
		if(!p[i])
			for(j=i*i;j<max;j+=i+i)
				p[j]=1;
	ind[2] = k;
	for(i=3;i<max;i+=2)
		if(!p[i])
			ind[i] = ++k;
	int t;
	scanf("%d",&t);
	printf("%d\n",ind[t]);
	return 0;
}
