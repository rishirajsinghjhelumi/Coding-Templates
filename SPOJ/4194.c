#include<stdio.h>
#include<algorithm>
#define max2 1000000
typedef long long int ll;
ll luckynum[max2],a[max2];
ll max=1000000,j,bit,num,count=0,cl=0,cluck=0,x,i;
ll digit_num(ll *b,ll bit)
{
	for(i=0,x=0;i<bit;i++)
		x = (x<<3) + (x<<1) + (b[i]?7:4);
	return x;
}
void generate_lucky_num()
{
	for(bit=1;bit<=12;bit++)
		for(j=0,num=1<<bit;j<num;j++)
		{
			ll b[12]={0},x=j,i=0;
			while(x)
				b[i++] = x&1?1:0,x>>=1;
			luckynum[cluck++] = digit_num(b,bit);
		}
	std::sort(luckynum,luckynum+cluck);
	count = cluck;
}
void dfs(ll t,ll k)
{
	ll i;
	for(i=k;i<count;i++)
	{
		ll tmp = t*luckynum[i];
		if(tmp <=max && tmp>0)
		{
			luckynum[cluck++] = tmp;
			dfs(tmp,i);
		}
		else
			break;
	}
}
int main()
{
	max*=max;
	generate_lucky_num();
	dfs(1,0);
	std::sort(luckynum,luckynum+cluck);
	count = 0;
	for(i=0;i<cluck;i++)
		if(luckynum[i]!=luckynum[i+1])
			a[count++] = luckynum[i];
	a[count] = max*10;
	ll t,A,B;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&A,&B);
		ll low=0,high=count,f1=0,f2=0,mid;
		while(low <= high)
		{   
			mid = (low + high) / 2;
			if(a[mid] == A)  
				f1 = 1;
			if(a[mid] > A)
				high = mid - 1;  
			else 
				low = mid + 1;
		}   
		ll c1 = high + 1;
		low = 0;  
		high = count;
		while(low <= high)
		{   
			mid = (low + high) / 2;
			if(a[mid] == B)  
				f2 = 1;
			if(a[mid] > B)
				high = mid - 1;
			else 
				low = mid + 1;
		}   
		ll c2 = high + 1;
		printf("%d\n",f1?abs(c2-c1)+1:abs(c2-c1));
	}
	return 0;
}
