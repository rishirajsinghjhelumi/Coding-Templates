#include<stdio.h>
#include<math.h>
#define max 1000001
#define m (max-1)>>1
#define x (floor(sqrt(max)-1))/2
typedef unsigned long long int ull;
ull i,j,k=0;
ull p[max];
ull primes[max];
ull fact[100],ind[100];
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
	ull t,a,K,n;
	scanf("%llu",&t);
	while(t--)
	{
		scanf("%llu%llu",&n,&K);
		ull j=0,l=0,s=sqrt(K),X,d=0,ans=1,check=1,min=1000000000000000000;
		while(K!=1)
		{
			X = primes[j];
			d = 0 ;
			while(!(K%X))
			{
				d++;
				K/=X;
			}
			if(d)
			{
				fact[l] = X;
				ind[l++] = d;
			}
			if(++j==k || X>=s)
				break;
		}
		if(K!=1)
		{
			fact[l] = K;
			ind[l++] = 1;
		}
		for(i=0;i<l;i++)
		{
			X = n;
			ull a = fact[i],c=0;
			while(X/a)
			{
				c += X/a;
				if(a>9223372036854775807/fact[i])
					break;
				a *= fact[i];
			//	printf("%llu %llu\n",a,X/a);
			}
			if(c/ind[i]<min)
				min = c/ind[i];
		}
		printf("%llu\n",min);
	}
	return 0;
}
