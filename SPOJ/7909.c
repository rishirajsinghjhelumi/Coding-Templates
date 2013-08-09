#include<stdio.h>
#include<algorithm>
#include<math.h>
typedef long long int ull;
ull a[15],n,m,i,done,minc,count,fact[100],ind[100],path[1000000],len=0;
int main()
{
	while(scanf("%llu%llu",&n,&m)>0)
	{
		for(i=0;i<m;i++)
			scanf("%llu",&a[i]);
		ull j=0,x=n,d=0,s=sqrt(n),p=0;
		len=0;
		done=0;
		std::sort(a,a+m);
		while(!(x%2))
		{
			d++;
			x>>=1;
		}
		if(d)
		{
			fact[j] = 2;
			ind[j++] = d;
		}
		for(i=3;i<=s;i+=2)
		{
			d=0;
			while(!(x%i))
			{
				d++;
				x/=i;
			}
			if(d)
			{
				fact[j] = i;
				ind[j++] = d;
			}
			if(x==1)
				break;
		}
	}
	return 0;
}
ull calc_path(ull *a,ull j,ull x)
{
	ull k;
	if(x==1)
	{
		done=1;
		m
	}
	for(k=m-1;k>=0;k--)
	{
		if(done)
			break;
		if(x%a[k]==0)
		{
			path[len++] = x/a[k];
			calc_path(a,j,x/a[k]);
		}
	}
}
