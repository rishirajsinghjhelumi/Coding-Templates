#include<stdio.h>
#include<math.h>
#define max 10000000
#define m (max-1)>>1
#define x (floor(sqrt(max)-1))/2
int i,j,k=1;
char p[m];
int primes[5010000];
int main()
{
	for(i=1;i<=x;i++)
		if(!p[i])
			for(j=((i+1)*i)<<1;j<=m;j+=(i<<1)+1)
				p[j]=1;
	primes[k++] = 2;
	for(i=1;i<=m;i++)
		if(!p[i])
			primes[k++] = (i<<1)+1;
	printf("%d\n",k);
	/*int t,n;
	scanf("%d",&t);
	while(t--&&scanf("%d",&n)&&printf("%d\n",primes[n]));*/
	return 0;
}
