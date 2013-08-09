#include<stdio.h>
#include<math.h>	
#define max 100000
typedef long long int ull;
ull primes[66]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317};
ull num[665][24000];
ull ind[665];
ull b_search(ull *a,ull x,ull high,ull low);
int main()
{
	ull i,j,k=66;
	num[0][ind[0]++]=1;
	num[1][ind[1]++]=3;
	ull m=0;
	for(i=3;i<=max;i++)
	{
		ull s=sqrt(i),d,n=i,j=0,x,ans=1;
		while(n!=1)
		{
			d=0;
			x = primes[j];
			while(!(n%x))
			{
				d++;
				n/=x;
			}
			if(d)
				ans = ans * ((d<<1)+1);
			if(++j==k || x>=s)
				break;
		}
		if(n!=1)
			ans *=3;
		ans = (ans-1)>>1;
		num[ans][ind[ans]++] = i*i;
	}
	ull t,K,low,high,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&K,&low,&high);
		if(k>1323)
			printf("0\n");
		else
		{
			K = (K-1)>>1;
			ull i;
			for(i=0;i<ind[K];i++)
			{
				if(num[K][i] >= low && num[K][i]<=high)
					counter++;
			}
			printf("%lld\n",counter);
		}
	}
	return 0;
}
