#include<stdio.h>
#include<math.h>
#include<assert.h>
#define mod 142857
typedef long long int ull;
ull val[4] = {27,11,13,37};
ull count[4] = {3,1,1,1};
ull fact[4][50];
ull inv[4];
ull power2(ull n ,ull k,ull mod1)
{
	ull ans=1;
	while(k>0)
	{
		if(k&1)
			ans = (ans*n)%mod1;
		k>>=1;
		n = (n * n)%mod1;
	}
	return ans%mod1;
}
ull minv(ull a, ull n) 
{
	ull i = n, v = 0, d = 1;
	while (a>0) 
	{
		ull t = i/a, x = a;
		a = i % x;
		i = x;
		x = d;
		d = v - t*x;
		v = x;
	}
	return (v+n)%n;
}
ull num_to_base(ull num, ull *a ,ull base)
{
	ull j = 0;
	while(num)
	{
		a[j++] = num%base;
		num /= base;
	}
	return j;
}
ull crt(ull *a)
{
	ull m1=27,m2=11,m3=13,m4=37;
	ull a1=a[0],a2=a[1],a3=a[2],a4=a[3];
	ull m = m1,s = a1;
	ull s1 = ((a2 - s + m2)*minv(m,m2))%m2;
	s = m*s1 + s;
	m *= m2;
	s1 = ((a3 - s + m3)*minv(m,m3))%m3;
	s = m*s1 + s;
	m *= m3;
	s1 = ((a4 - s + m4)*minv(m,m4))%m4;
	s = m*s1 + s;
	m *= m4;
	return (s+mod)%mod;
}
ull power(ull n,ull num)
{
	ull x=0,p=num,s=num;
	while(1)
	{
		ull a = n/s;
		if(!a)
			break;
		x+=a;
		s*=p;
	}
	return x;
}
ull least_residue(ull n, ull *a)
{
	ull x = 3;
	ull p = 1;
	ull j = 0;
	while(1)
	{
		if(n/p == 0)
			break;
		a[j++] = (n/p)%27;
		p *= x;
	}
	return j;
}
ull solve(ull n,ull r)
{
	ull i,j;
	ull ans[4];
	for(j=0;j<4;j++)
	{
		ull a[20] = {0},b[20]={0},c[20]={0},x,d,m=val[j];
		d = num_to_base(n,a,m);
		x = num_to_base(r,b,m);
		ans[j] = 1;
		x = val[j];
		for(i=0;i<d;i++)
		{
			ans[j] = ( ans[j] * fact[j][a[i]] + x) % x;
			ans[j] = ( ans[j] * minv(fact[j][b[i]],x) + x) % x;
			ans[j] = ( ans[j] * minv(fact[j][a[i]-b[i]],x) + x) % x;
		}
		if(!j)
		{
			ull a[20] = {0},b[20]={0},c[20]={0},x,d,m=val[j];
			d = least_residue(n,a);
			x = least_residue(r,b);
			x = least_residue(n-r,c);
			ans[j] = 1;
			x = val[j];
			for(i=0;i<d;i++)
			{
				ans[j] = ( ans[j] * fact[j][a[i]]) % x;
				if(ans[j]==0)
					ans[j] = x;
				ans[j] = ( ans[j] * minv(fact[j][b[i]],x)) % x;
				if(ans[j]==0)
					ans[j] = x;
				ans[j] = ( ans[j] * minv(fact[j][c[i]],x)) % x;
				if(ans[j]==0)
					ans[j] = x;
			}
			ull eq = 0;
			ull pp = power2(3,power(n,3)-power(r,3)-power(n-r,3),x);
			ans[j] = (ans[j] * pp)%x;
				pp = x;
			ull sign = eq%2==1?-1:1;
			ans[j] = (ans[j]* sign + x)%x;
		}
	}
	ull answ=0;
	for(j=0;j<4;j++)
		answ = (answ + ( ( ans[j] * inv[j] )  * (mod/val[j]) )%mod )%mod;
	return (answ+3*mod)%mod;
}
int main()
{
	ull i,j;
	for(j=0;j<4;j++)
	{
		ull x = val[j];
		fact[j][0] = 1;
		if(!j)
		{
			for(i=1;i<=x;i++)
			{
				ull s = i;
				while(!(s%3))
					s /= 3;
				fact[j][i] = (fact[j][i-1] * s) % x;
			}
		}
		else
		{
			for(i=1;i<=x;i++)
				fact[j][i] = (fact[j][i-1] * i) % x;
		}
		inv[j] = minv(mod/val[j],val[j]);
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ull n,r;
		scanf("%lld%lld",&n,&r);
		printf("%lld\n",(solve(n,r)+mod)%mod);
	}
	return 0;
}
