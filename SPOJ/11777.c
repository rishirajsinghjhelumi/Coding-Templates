#include<stdio.h>
#define mod 1000000007
typedef unsigned long long int ull;
ull p1,p2;
ull fib(ull a,ull b,ull n)
{
	ull mo = mod-1;
	ull m[2][2]={{a,b},{1,0}},ans[2][2]={{1,0},{0,1}},t=1;
	while(n)
	{
		ull x=m[0][0],y=m[0][1],z=m[1][0],w=m[1][1];
		if(n&t)
		{
			ull t1=ans[0][0],t2=ans[0][1],t3=ans[1][0],t4=ans[1][1];
			ans[0][0] = (x*t1+y*t3)%mo;
			ans[0][1] = (x*t2+y*t4)%mo;
			ans[1][0] = (z*t1+w*t3)%mo;
			ans[1][1] = (z*t2+w*t4)%mo;
			n-=t;
		}
		t<<=1;
		m[0][0] = (x*x+y*z)%mo;
		m[0][1] = (x*y+y*w)%mo;
		m[1][0] = (x*z+z*w)%mo;
		m[1][1] = (z*y+w*w)%mo;
	}
	p1 = ans[1][1];
	p2 = ans[1][0];
}
ull power(ull n ,ull k)
{
	if(!k)
		return 1;
	ull temp = 1,ans=1;
	while(k>0)
	{   
		if(k&temp)
		{   
			ans = (ans*n)%mod;
			k-=temp;
		}   
		temp <<=1;
		n = (n * n)%mod;
	}   
	return ans%mod;
}
int main()
{
	ull n,t,f0,f1,k,a1,a2;
	scanf("%llu",&t);
	while(t-- && scanf("%llu%llu%llu%llu",&f0,&f1,&n,&k))
	{
		fib(k,k,n);
		a1 = power(f0,p1);
		a2 = power(f1,p2);
		printf("%llu\n",(a1*a2)%mod);
	}
	return 0;
}
