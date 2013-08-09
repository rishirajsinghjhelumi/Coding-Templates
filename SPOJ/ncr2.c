#include<stdio.h>
#include<math.h>
#include<assert.h>
#define mod 142857
typedef long long int ull;
ull val[4] = {3,11,13,37};
ull count[4] = {3,1,1,1};
ull a[mod+10];
ull power2(ull n ,ull k)
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
int power(ull n,ull num)
{
	ull x = num;
	int ans = 0;
	while(x <= n)
	{
		ans += n/x;
		x*=num;
	}
	return ans;
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
int main()
{
	ull i=0,j;
	a[i] = 1;
	for(i=1;i<=mod;i++)
	{
		ull x = i;
		for(j=0;j<4;j++)
			while(!(x%val[j]))
				x /= val[j];
		a[i] = (a[i-1] * x)%mod;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ull n,r;
		scanf("%lld%lld",&n,&r);
		int i,s1[4]={0},s2[4]={0},check = 0;
		for(i=0;i<4;i++)
		{
			s1[i] = power(n,val[i]);
			s2[i] = power(r,val[i]) + power(n-r,val[i]);
			if(s1[i]-s2[i] < count[i])
				check = 1;
		}
		if(check)
		{
			ull b[5]={0},c[5]={0};
			ull x = num_to_base(n,b,mod);
			ull x1 = num_to_base(r,c,mod);
			ull ans = 1;
			for(i=0;i<=x;i++)
			{
				ans = ( a[b[i]] * minv(a[c[i]],mod) )%mod;
				ans =  (ans * minv(a[b[i]-c[i]],mod) )%mod;
			}
			for(i=0;i<4;i++)
				ans = ( ans * power2(val[i],s1[i]-s2[i]) )%mod;
			printf("%lld\n",ans);
		}
		else
			printf("0\n");
	}
	return 0;
}
