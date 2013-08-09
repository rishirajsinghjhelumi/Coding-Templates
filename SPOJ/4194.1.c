#include<stdio.h>
#include<algorithm>
#define max2 10000
typedef long long int ll;
ll luckynum[max2],cluck=0;
ll a[1000000],b[1000000],cl=0,count=0;
ll ans[1000000],counter=0;
ll digit_num(ll *b,ll bit);
ll max=1000000;
void generate_lucky_num()
{
	ll bit;
	for(bit=1;bit<=12;bit++)
	{
		ll num = 1<<bit,j;
		for(j=0;j<num;j++)
		{
			ll b[12]={0},x=j,i=0;
			while(x)
				b[i++] = x&1?1:0,x>>=1;
			luckynum[cluck++] = digit_num(b,bit);
		}
	}
}
ll digit_num(ll *b,ll bit)
{
	ll x=0,i;
	for(i=0;i<bit;i++)
		x = (x<<3) + (x<<1) + (b[i]?7:4);
	return x;
}
int main()
{
	generate_lucky_num();
	ll i,j,x,r;
	max*=max;
	for(i=0;i<126;i++)
	{
		x = luckynum[i];
		r = 1;
		while(1)
		{

			if(r>max/x)
				break;
			r*=x;
			a[cl++] = r;
		}
	}
	for(i=126;i<cluck;i++)
		a[cl++] = luckynum[i];
	printf("%lld\n",cl);
	std::sort(a,a+cl);
	for(i=0;i<cl;i++)
	{
		x = a[i];
		b[count++]=a[i];
		for(j=0;j<cl;j++)
		{
			if(x>max/a[j])
				break;
			b[count++] = a[j]*x;
		}
	}
	std::sort(b,b+count);
	printf("%lld\n",count);
	for(i=0;i<count;i++)
		if(b[i]!=b[i+1])
			ans[counter++] = b[i];
	printf("%lld\n",counter);
	/*ll t,A,B;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&A,&B);
		A--;
		ll c1,c2;
		for(i=0;i<counter;i++)
			if(ans[i]>A)
				break;
		c1 = i;
		for(i=0;i<counter;i++)
			if(ans[i]>B)
				break;
		c2 = i;
		printf("%lld\n",c2-c1);
	}*/
	return 0;
}
