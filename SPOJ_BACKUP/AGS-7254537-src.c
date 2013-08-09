#include<stdio.h>
typedef long long int ull;
ull xx,yy;
ull fib(ull r,ull n,ull mod)
{
	ull m[2][2]={{1+r,-r},{1,0}},ans[2][2]={{1,0},{0,1}},t=1,k=n;
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
	return (ans[0][0]*xx+ans[0][1]*yy+k*mod)%mod;
}
int main()
{
	ull t;
	scanf("%lld",&t);
	while(t--)
	{
		ull a,d,r,n,mod,term[6],ans,z;
		scanf("%lld%lld%lld%lld%lld",&a,&d,&r,&n,&mod);
		term[1] = yy = a%mod;
		term[2] = (term[1] + d)%mod;
		term[3] = xx = (term[2]*r)%mod;
		term[4] = (term[3] + d)%mod;
		if(n<=4)
			ans = term[n];
		else
		{
			if(n&1)
			{
				z = ((n+1)/2 - 2);
				ans = (fib(r,z,mod) + n*mod)%mod;
			}
			else
			{
				z = (n/2 - 2);
				ans  = (fib(r,z,mod)+d+n*mod)%mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
