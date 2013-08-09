#include<stdio.h>
#include<math.h>
typedef unsigned long long int ull;
ull gcd(ull a,ull b);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		ull n,x,lcm,i,j=0,a[10000],d=0,f;
		scanf("%llu",&n);
		scanf("%llu",&x);
		lcm = x;
		for(i=1;i<n;i++)
		{
			scanf("%llu",&x);
			lcm = (x*lcm)/gcd(x,lcm);
		}
		x = sqrt(lcm);
		while(lcm%2==0)
		{
			lcm>>=2;
			d=1;
		}
		if(d==1)
			a[j++] = 2;
		d=0;
		while(lcm%3==0)
		{
			lcm /=3;
			d=1;
		}
		if(d==1)
			a[j++] = 3;
		i=1;
		while(1)
		{
			f = 6*i - 1;
			if(f>x)
				break;
			d=0;
			while(lcm%f==0)
			{
				lcm /= f;
				d=1;
			}
			if(d==1)
				a[j++] = f;
			d=0;
			f= 6*i + 1;
			if(f>x)
				break;
			while(lcm%f==0)
			{
				lcm /= f;
				d=1;
			}
			if(d==1)
				a[j++] = f;
			i++;
		}
		for(i=0;i<j;i++)
			printf("%llu\n",a[i]);
	}
	return 0;
}
ull gcd(ull a,ull b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
