#include<stdio.h>
typedef long long int ull;
ull fib(ull n,ull mod)
{
	ull m[2][2]={{1,1},{1,0}},ans[2][2]={{1,0},{0,1}},t=1;
	while(n)
	{
		ull x=m[0][0],y=m[0][1],z=m[1][0],w=m[1][1];
		if(n&t)
		{
			ull t1=ans[0][0],t2=ans[0][1],t3=ans[1][0],t4=ans[1][1];
			ans[0][0] = (x*t1+y*t3)%mod;
			ans[0][1] = (x*t2+y*t4)%mod;
			ans[1][0] = (z*t1+w*t3)%mod;
			ans[1][1] = (z*t2+w*t4)%mod;
			n-=t;
		}
		t<<=1;
		m[0][0] = (x*x+y*z)%mod;
		m[0][1] = (x*y+y*w)%mod;
		m[1][0] = (x*z+z*w)%mod;
		m[1][1] = (z*y+w*w)%mod;
	}
	return ans[0][0];
}
int main()
{
	ull a,b,n,t,mod;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%llu%llu",&n,&mod);
		a = (fib(n+1,mod)*2-2-n+n*mod)%mod;
		printf("%lld\n",a);

	}
	return 0;
}
