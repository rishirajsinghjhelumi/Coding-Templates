#include<stdio.h>
typedef unsigned long long int ull;
ull p1,p2;
ull fib(ull a,ull b,ull n,ull mo)
{
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
int main()
{
	ull n,t,a,b,k,a1,m;
	scanf("%llu",&t);
	while(t-- && scanf("%llu%llu%llu%llu",&a,&b,&n,&m))
	{
		fib(1,1,n+1,m);
		a1 = ((a*p1)%m+(b*p2)%m-b+m)%m;
		printf("%llu\n",a1);
	}
	return 0;
}
