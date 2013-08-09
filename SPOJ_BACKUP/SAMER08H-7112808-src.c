#include<stdio.h>
#include<math.h>
typedef long long int ll;
ll a1,a2,b1,b2,c1,c2,d1,d2,ta,tb,q1,q2,x,i,n1,d11,n2,d22;
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
void calculate();
int main()
{
	while(scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&a1,&b1,&c1,&d1,&a2,&b2,&c2,&d2)==8 && (a1|a2|b1|b2|c1|c2|d1|d2)!=0)
	{
		calculate();
		n1 = ta;
		d11 = tb;
		a2 *=-1;
		b2 *=-1;
		d2 += 180;
		calculate();
		n2 = ta;
		d22 = tb;
		if(n1==999999 && n2==999999)
			ta = tb = 0;
		else if(n1*d22>n2*d11)
			ta = n2,tb=d22;
		else
			ta = n1,tb=d11;
		printf("%lld %lld\n",ta,tb);
	}
	return 0;
}
void calculate()
{
	int correct = 1;
	ta = b2 - b1;
	tb = a1 - a2;
	if(tb==0)
	{
		if(ta==0)
		{
			if(d1<0)
				d1=360*(long)ceil(d1/-360.0)+d1;
			else 
				d1=d1%360;
			if(d2<0)
				d2=360*(long)ceil(d2/-360.0)+d2;
			else 
				d2=d2%360;
			ta = d2 - d1;
			tb = c1 - c2;
			if(tb<0)
			{
				ta *=-1;
				tb *=-1;
			}
			if(ta<0)
				ta=360*(long)ceil(ta/-360.0)+ta;
			if(tb==0)
			{
				if(ta==0)
					tb = 1;
				else
					correct = 0;
			}
			else if(ta==0)
				tb = 1;
			else
			{
				x = gcd(ta,tb);
				ta /=x;
				tb /=x;
			}
		}
		else
			correct = 0;
	}
	else if(ta*tb>=0)
	{
		if(ta==0)
			tb=1;
		else
		{
			ta = abs(ta);
			tb = abs(tb);
			x = gcd(ta,tb);
			ta /=x;
			tb /=x;
		}
		if(correct)
		{
			q1 = c1 * ta + d1 * tb;
			q2 = c2 * ta + d2 * tb;
			correct = (a1*ta+b1*tb==0)||((q1-q2)%(360*tb)==0);
		}	
	}
	else
		correct = 0;
	if(correct==0)
	{
		ta = 999999;
		tb = 1;
	}
}
