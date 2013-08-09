#include<stdio.h>
#include<math.h>
#define mod 1000000000
typedef unsigned long long int ull;
ull f[1000010];
ull power(ull n ,ull k)
{
	ull ans=1;
	while(k>0)
	{
		if(k&1)
			ans = (ans*n)%mod;
		k>>=1;
		n = (n * n)%mod;
	}
	return ans%mod;
}
int main()
{
	ull i,j,k,n;
	f[0]=f[1]=f[2]=1;
	f[3]=f[4]=3;
	f[5]=f[6]=15;
	f[7]=f[8]=f[9]=f[10]=105;
	for(n=11;n<=1000000;n++)
		f[n] = (((power(2,n%4?(n>>2)+1:n>>2)*f[n%5?n/5+1:n/5])%mod)*f[n%10?n/10+1:n/10])%mod;
	for(i=0;i<100;i++)
		printf("%llu %llu\n",i,f[i]);
	return 0;
}
