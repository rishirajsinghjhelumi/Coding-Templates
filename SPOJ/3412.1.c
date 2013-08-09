#include<stdio.h>
typedef long long int ll;
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	ll a1,a2,b1,b2,c1,c2,d1,d2,ta,tb,q1,q2,x,i;
	while(scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&a1,&b1,&c1,&d1,&a2,&b2,&c2,&d2)==8 && (a1|a2|b1|b2|c1|c2|d1|d2)!=0)
	{
		ta = b2 - b1;
		tb = a1 - a2;
		if( (ta > 0 && tb >0) || (ta < 0 && tb < 0) )
		{
			if(ta<0 && tb<0)
				ta = -1 * ta , tb = -1 * tb;
			x = gcd(ta,tb);
			ta /= x;
			tb /= x;
			q1 = (c1 * ta + d1 * tb)%360;
			q2 = (c2 * ta + d2 * tb)%360;
			if(q1 != q2)
				ta = tb = 0;
		}
		else if(ta==0 && tb!=0)
		{
			if(d1==d2)
				ta = 0 , tb = 1;
			else
				ta = 0 , tb = 0;
		}
		else if(ta!=0 && tb==0)
			ta = tb = 0;
		else if(ta==0 && tb ==0)
		{
			ta = d2 - d1;
			tb = c1 - c2;
			if( (ta>0 && tb>0) || (ta<0 && tb<0))
			{
				if(ta<0 && tb<0)
					ta = -1*ta , tb = -1*tb;
				x=gcd(ta,tb);
				ta /=x;
				tb /=x;
			}
			else if(ta==0 && tb==0)
				ta = 0 , tb = 1;
			else if(ta==0 && tb!=0)
				ta = 0, tb = 1;
			else
				ta = tb = 0;
		}
		else
			ta = tb = 0;
		printf("%lld %lld\n",ta,tb);
	}
	return 0;
}
